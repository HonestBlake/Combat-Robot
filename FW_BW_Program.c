//This Program implements a simple pattern, moving the rover forward and Backward. 
/* Pin Connections
5v -> 5v
Gnd -> Gnd
ENA -> P2.4
ENB -> P2.5
In1 -> P2.0
In2 -> P2.6
In3 -> P2.2
In4 -> P2.3

J3 & J5 Motor A
J1 & J2 Motor B
*/ 

#include <msp430.h>

volatile unsigned int ms_count = 0;

void delay_ms(unsigned int ms);

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // Stop watchdog timer

    // --- Setup Timer_A ---
    TA0CCR0 = 1000 - 1;              // 1000 ticks = 1 ms (assuming SMCLK ~1 MHz)
    TA0CCTL0 = CCIE;                 // Enable CCR0 interrupt
    TA0CTL = TASSEL_2 + MC_1;        // SMCLK, Up mode

    // --- Motor control pins ---
    // IN1=P2.0, IN2=P2.6, IN3=P2.2, IN4=P2.3, ENA=P2.4, ENB=P2.5
    P2DIR |= BIT0 | BIT2 | BIT3 | BIT4 | BIT5 | BIT6;
    P2OUT &= ~(BIT0 | BIT2 | BIT3 | BIT4 | BIT5 | BIT6);

    // Enable motors
    P2OUT |= BIT4 | BIT5;

    __enable_interrupt();  // Enable global interrupts

    while (1)
    {
        // ---- Both motors forward ----
        P2OUT |=  BIT0;
        P2OUT &= ~BIT6;
        P2OUT |=  BIT2;
        P2OUT &= ~BIT3;
        delay_ms(2000);

        // ---- Brake ----
        P2OUT |=  BIT0 | BIT6;
        P2OUT |=  BIT2 | BIT3;
        delay_ms(1000);

        // ---- Both motors backward ----
        P2OUT &= ~BIT0;
        P2OUT |=  BIT6;
        P2OUT &= ~BIT2;
        P2OUT |=  BIT3;
        delay_ms(2000);

        // ---- Brake ----
        P2OUT |=  BIT0 | BIT6;
        P2OUT |=  BIT2 | BIT3;
        delay_ms(1000);
    }
}

void delay_ms(unsigned int ms)
{
    ms_count = 0;
    while (ms_count < ms);
}

#pragma vector=TIMER0_A0_VECTOR
__interrupt void Timer0_A0_ISR(void)
{
    ms_count++;
}


