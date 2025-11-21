#include <msp430.h>

void delay_ms(unsigned int ms);
void setServoPulse(unsigned int pulse_us);

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;      // Stop watchdog
    PM5CTL0 &= ~LOCKLPM5;          // Unlock GPIO (FRAM devices!)

    // --- Buttons on P1.1 and P1.2 (active LOW) ---
    P1DIR &= ~(BIT1 | BIT2);       // Inputs
    P1REN |=  (BIT1 | BIT2);       // Enable pull resistors
    P1OUT |=  (BIT1 | BIT2);       // Pull-up (buttons to GND)

    // --- Servo PWM on P1.6 = TA0.1 ---
    P1DIR  |= BIT6;                // P1.6 as output
    P1SEL0 |= BIT6;                // Select TA0.1 function
    P1SEL1 |= BIT6;                // (TA0.1 is the tertiary function on P1.6)

    // --- Timer0_A setup for ~20 ms period (50 Hz) ---
    // Assume SMCLK ≈ 1 MHz (default DCO)
    TA0CCR0  = 20000 - 1;          // 20,000 counts = 20 ms
    TA0CCTL1 = OUTMOD_7;           // Reset/Set PWM mode
    TA0CCR1  = 1000;               // 1.0 ms pulse (~0°)
    TA0CTL   = TASSEL_2 | MC_1 | TACLR;   // SMCLK, up mode, clear TAR

    while (1)
    {
        // --- P1.1 pressed? -> go to ~90° (1.5 ms pulse) ---
        if (!(P1IN & BIT1))        // active LOW
        {
            setServoPulse(1500);
            delay_ms(200);         // debounce
            while (!(P1IN & BIT1)); // wait for release
            delay_ms(20);
        }

        // --- P1.2 pressed? -> go back to 0° (1.0 ms pulse) ---
        if (!(P1IN & BIT2))
        {
            setServoPulse(1000);
            delay_ms(200);         // debounce
            while (!(P1IN & BIT2)); // wait for release
            delay_ms(20);
        }
    }
}

void setServoPulse(unsigned int pulse_us)
{
    // basic bounds, adjust if your servo likes 500–2500 µs etc.
    if (pulse_us < 500)  pulse_us = 500;
    if (pulse_us > 2500) pulse_us = 2500;

    TA0CCR1 = pulse_us;           // directly sets PWM high time
}

void delay_ms(unsigned int ms)
{
    while (ms--)
        __delay_cycles(1000);     // ~1 ms at 1 MHz
}


