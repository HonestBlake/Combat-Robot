// Group 6 Final Project
// Austin George, Preston Clayton, Francisco Sisneros
// ECE-3363-001

#include <msp430.h>

// Motor Driver Pins
#define STBY_PIN   BIT3    // P3.3
#define AIN1_PIN   BIT0    // P2.0
#define AIN2_PIN   BIT3    // P2.3
#define BIN1_PIN   BIT0    // P3.0
#define BIN2_PIN   BIT1    // P3.1
#define PWMA_PIN   BIT6    // P2.6 TB0.5
#define PWMB_PIN   BIT7    // P2.7 TB0.6

// IR Sensor Pins
#define IR_LEFT    BIT4    // P1.4
#define IR_CENTER  BIT0    // P4.0
#define IR_RIGHT   BIT1    // P4.1

// Start BTN
#define BTN     BIT1    // P1.1

// Ultrasonic Pins
#define TRIG    BIT5    // P1.5
#define ECHO    BIT6    // P1.6 → TA0.CCI1A

#define LCD_CHAR_I 0x0000       //off
#define LCD_CHAR_N 0x0000       //off

// PWM
#define PWM_PERIOD 1000

// LCD segment low upper (high byte segments, low byte = DP)
const unsigned int lcd_to_num[10] = {
    0xFC00,0x6000,0xDB00,0xF300,
    0x6700,0xB700,0xBF00,0xE400,
    0xFF00,0xF700
};
#define LCD_DP     0x0001

// Variables for ultrasonic timing
unsigned int echo_start = 0;
unsigned int echo_width = 0;

// 62.5 ms ticks, do work every 8 ticks (~500 ms)
#define CCR0_TICKS 62500u
unsigned char tick_count = 0;

// Functions
// Self Explanatory
void trigger_pulse(void);
void lcd_load_digit(unsigned char position, unsigned int segments);
void display_inches(unsigned int us);

// Functions that deal with the movent of the rover
void motorA(unsigned char dir, unsigned int speed);
void motorB(unsigned char dir, unsigned int speed);
void motorsStandby(unsigned char standby_on);
void followLine(void);

// CCR0: scheduler (every CCR0_TICKS at 1 MHz)
#pragma vector = TIMER0_A0_VECTOR
__interrupt void Timer0_A0_ISR(void) {
    TA0CCR0 += 10000;
    if (++tick_count < 8) return;
    tick_count = 0;

    // 1) fire ultrasonic
    trigger_pulse();

    // 2) upperdate dispeedlay & motors
    display_inches(echo_width);
    if ((echo_width/148) <= 4) {
        motorA(3,0);  // BRAKE
        motorB(3,0);
    } else {
        followLine();
    }
}

// CCR1: capture rising/falling edges of ECHO
#pragma vector = TIMER0_A1_VECTOR
__interrupt void Timer0_A1_ISR(void) {
    switch (TA0IV) {
      case TA0IV_TACCR1:
        if (TA0CCTL1 & CCI)
            echo_start = TA0R;
        else {
            unsigned int now = TA0R;
            echo_width = (now >= echo_start)
                       ? now - echo_start
                       : (0xFFFF - echo_start + now);
        }
        break;
      default: break;
    }
}

// Main Function
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;   // stop WDT

    // BTN
    P1DIR &= ~BTN;
    P1REN |= BTN;
    P1OUT |= BTN;

    // Motors
    P2DIR |= AIN1_PIN|AIN2_PIN;
    P3DIR |= BIN1_PIN|BIN2_PIN|STBY_PIN;
    P2OUT &= ~(AIN1_PIN|AIN2_PIN);
    P3OUT &= ~(BIN1_PIN|BIN2_PIN|STBY_PIN);

    // PWM outputs
    P2DIR |= PWMA_PIN|PWMB_PIN;
    P2SEL0 |= PWMA_PIN|PWMB_PIN;
    P2SEL1 &= ~(PWMA_PIN|PWMB_PIN);

    // IR sensors
    P1DIR &= ~IR_LEFT;
    P1REN |= IR_LEFT;
    P1OUT &= ~IR_LEFT;

    P4DIR &= ~(IR_CENTER|IR_RIGHT);

    P4REN |=  IR_CENTER|IR_RIGHT;

    P4OUT &= ~(IR_CENTER|IR_RIGHT);

    // US Trigger
    P1SEL0 &= ~TRIG;
    P1SEL1 &= ~TRIG;
    P1DIR  |=  TRIG;
    P1OUT  &= ~TRIG;
    // US Echo
    P1SEL0 |=  ECHO;
    P1SEL1 |=  ECHO;
    P1DIR  &= ~ECHO;

    //Timer Configuration
    TB0CTL   = TBSSEL__SMCLK + MC__UP + TBCLR;
    TB0CCR0  = PWM_PERIOD - 1;
    TB0CCTL5 = OUTMOD_7;
    TB0CCR5 = 0;
    TB0CCTL6 = OUTMOD_7;
    TB0CCR6 = 0;


    // Clock Configuration
    CSCTL0_H = CSKEY_H;
    CSCTL1   = DCOFSEL_0;
    CSCTL2   = SELA__VLOCLK|SELS__DCOCLK|SELM__DCOCLK;
    CSCTL3   = DIVA__1|DIVS__1|DIVM__1;
    CSCTL0_H = 0;

    // LCD Configuration
    LCDCPCTL0  = 0b1111111111010000;
    LCDCPCTL1  = 0b1111100000111111;
    LCDCPCTL2  = 0b0000000011111000;
    LCDCCTL0   = LCDDIV__1|LCDPRE__16|LCD4MUX|LCDLP;
    LCDCMEMCTL = LCDCLRM;  while(LCDCMEMCTL & LCDCLRM);
    LCDCCTL0  |= LCDON;

    // Ultrasonic Configuration
    // CCR1 capture
    TA0CCTL1 = CM_3|CCIS_0|SCS|CAP|CCIE;
    // CCR0 periodic interrupt
    TA0CCR0  = CCR0_TICKS;
    TA0CCTL0 = CCIE;
    TA0CTL   = TASSEL__SMCLK | MC__CONTINUOUS | TACLR;

    // Turn motors off/ at rest
    motorsStandby(0);

    // wait for BTN (active-low)

    PM5CTL0 &= ~LOCKLPM5;       // unlock GPIO

    while (P1IN & BTN);    __delay_cycles(100000);
    while (!(P1IN & BTN)); __delay_cycles(100000);
    motorsStandby(1);

    __enable_interrupt();
    __bis_SR_register(LPM0_bits + GIE);  // all work in ISRs
    for(;;);
}
// Function to create trigger pulse
void trigger_pulse(void) {
    P1OUT |= TRIG;
    __delay_cycles(10);
    P1OUT &= ~TRIG;
}

// Classic LCD dislay loader.
void lcd_load_digit(unsigned char position, unsigned int segmstandby_onts) {
    unsigned char upper = segmstandby_onts>>8, lower = segmstandby_onts&0xFF;
    switch(position) {
      case 1: LCDM10 = upper; LCDM11 = lower; break;
      case 2: LCDM6  = upper; LCDM7  = lower; break;
      case 3: LCDM4  = upper; LCDM5  = lower; break;
      case 4: LCDM19 = upper; LCDM20 = lower; break;
      case 5: LCDM15 = upper; LCDM16 = lower; break;
      case 6: LCDM8  = upper; LCDM9  = lower; break;
    }
}

// Function that displays the distance measured by the ultrasonic sensor
void display_inches(unsigned int us) {
    // hundredths of an inch (rounded)
    // Creating different digit values.
    unsigned long tmp = (unsigned long)us*100 + 74;
    unsigned int ih   = tmp/148;
    unsigned int whole= ih/100, frac= ih%100;
    unsigned int d1=whole/10, d2=whole%10, d3=frac/10, d4=frac%10;

    //loading digits to display
    lcd_load_digit(1, d1?lcd_to_num[d1]:0);
    lcd_load_digit(2, lcd_to_num[d2] | LCD_DP);
    lcd_load_digit(3, lcd_to_num[d3]);
    lcd_load_digit(4, lcd_to_num[d4]);
    lcd_load_digit(5, LCD_CHAR_I);
    lcd_load_digit(6, LCD_CHAR_N);
}

// Function that takes in a direction and a speed and then
// sets and resets specific pins so that the desired output is reached.

// left motor
void motorA(unsigned char dir, unsigned int speed) {
    if (speed> PWM_PERIOD) speed=PWM_PERIOD;
    switch(dir) {
      case 1: P2OUT |= AIN1_PIN; P2OUT &= ~AIN2_PIN; TB0CCR5=speed; break;
      case 2: P2OUT &= ~AIN1_PIN;P2OUT |= AIN2_PIN; TB0CCR5=speed; break;
      case 3: P2OUT |=AIN1_PIN|AIN2_PIN; TB0CCR5=0; break;
      case 4: P2OUT &=~(AIN1_PIN|AIN2_PIN); TB0CCR5=0; break;
    }
}

// Same as function above, just for right motor.
void motorB(unsigned char dir, unsigned int speed) {
    if (speed> PWM_PERIOD) speed=PWM_PERIOD;
    switch(dir) {
      case 1: P3OUT |= BIN1_PIN; P3OUT &= ~BIN2_PIN; TB0CCR6=speed; break;
      case 2: P3OUT &= ~BIN1_PIN;P3OUT |= BIN2_PIN;  TB0CCR6=speed; break;
      case 3: P3OUT |=BIN1_PIN|BIN2_PIN; TB0CCR6=0; break;
      case 4: P3OUT &=~(BIN1_PIN|BIN2_PIN); TB0CCR6=0; break;
    }
}

// To have the motors not turn on all the time.
void motorsStandby(unsigned char standby_on) {
    if (standby_on) P3OUT |= STBY_PIN; else P3OUT &= ~STBY_PIN;
}

void followLine(void) {
    // sample each sstandby_onsor as 0 or 1
    unsigned char LS = (P1IN & IR_LEFT)   ? 1 : 0;
    unsigned char CS = (P4IN & IR_CENTER) ? 1 : 0;
    unsigned char RS = (P4IN & IR_RIGHT)  ? 1 : 0;

    // ps - had to increase the motorB speed by a little bit
    // because it kept getting stuck and this seemed to somewhat
    // solve that issue
    if ( CS && !LS && !RS ) {
        // perfectly cstandby_ontered
        motorA(1, 500);
        motorB(1, 500);
    }
    else if (!CS && !LS && !RS) {
        // no line: slow and straight
        motorA(1, 300);
        motorB(1, 350);
    }
    else if ( LS && !CS && !RS ) {
        // line only on left: turn left
        motorA(1, 0);
        motorB(1, 450);
    }
    else if ( RS && !CS && !LS ) {
        // line only on right:turn right
        motorA(1, 450);
        motorB(1, 0);
    }
    else if ( LS && CS && !RS ) {
        // left+cstandby_onter: turn left
        motorA(1, 0);
        motorB(1, 450);
    }
    else if ( RS && CS && !LS ) {
        // right+cstandby_onter: turn right
        motorA(1, 400);
        motorB(1, 0);
    }
    else if (!LS && CS && !RS) {
        // center: go straight
        motorA(1, 500);
        motorB(1, 550);
    }
    else {
        // all three or something else: go straight
        motorA(1, 500);
        motorB(1, 550);
    }
}
