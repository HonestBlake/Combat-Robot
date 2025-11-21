#include <msp430.h>

void delay_ms(unsigned int ms);
void setServoPulse(unsigned int pulse);

void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // Stop watchdog timer

    // --- Configure buttons ---
    // P2.1 -> Button 1 (turn 90°)
    P2DIR &= ~BIT1;   // Input
    P2REN |= BIT1;    // Enable pull resistor
    P2OUT |= BIT1;    // Pull-up (button to GND)

    // P1.1 -> Button 2 (reset 0°)
    P1DIR &= ~BIT1;   // Input
    P1REN |= BIT1;    // Enable pull resistor
    P1OUT |= BIT1;    // Pull-up (button to GND)

    // --- Configure servo output on P1.2 (TA0.1) ---
    P1DIR |= BIT2;    // Output
    P1SEL |= BIT2;    // TA0.1 function

    // --- Setup Timer0_A for 20 ms period ---
    TA0CCR0 = 20000 - 1;      // 20 ms period (1 MHz SMCLK)
    TA0CCTL1 = OUTMOD_7;      // Reset/Set output mode
    TA0CCR1 = 1000;           // Initial pulse = 1.0 ms (0° position)
    TA0CTL = TASSEL_2 + MC_1; // SMCLK, Up mode

    while (1)
    {
        // Button on P2.1 pressed? (active low)
        if (!(P2IN & BIT1))
        {
            setServoPulse(4000);  // move to 90°
            delay_ms(500);        // debounce delay
            while (!(P2IN & BIT1)); // wait for release
        }

        // Button on P1.1 pressed? (active low)
        if (!(P1IN & BIT1))
        {
            setServoPulse(1000);  // reset to 0°
            delay_ms(500);        // debounce delay
            while (!(P1IN & BIT1)); // wait for release
        }
    }
}

// --- Helper: set servo pulse width (µs) ---
void setServoPulse(unsigned int pulse)
{
    TA0CCR1 = pulse;  // Set PWM high time (e.g., 1000–2000 µs)
}

// --- Simple delay function (approximate) ---
void delay_ms(unsigned int ms)
{
    while (ms--)
        __delay_cycles(1000);  // 1 MHz -> 1 ms
}

