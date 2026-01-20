#include "robot.hpp"
#include "device.hpp"
#include "pins.hpp"
#include "robotValues.hpp"

namespace combatRobot::coreRobot::robot{ // #scope: robot

// Public Factory Methods

    Robot::Robot(): m_redLED(RED_LED_PORT, State::LOW), m_greenLED(GREEN_LED_PORT, State::LOW), m_ir(IR_IN, BIT_PERIOD), m_left(LEFT_IN1, LEFT_IN2, LEFT_ENA), m_right(RIGHT_IN1, RIGHT_IN2, RIGHT_ENA){
        configureServo();
    }

// Public Methods 

   

    void Robot::run(){
        Device::stopWDT();
        Device::enableGPIO();
        m_greenLED.write(State::HIGH);



        // m_redLED.write(State::LOW);
        // Device::delay(1000);
        // m_redLED.write(State::HIGH);

        // TB0CCR1 = us_to_ticks(MAX_PULSE_US);
        // TB0CTL = TBSSEL__SMCLK | MC__UP | TBCLR;

        // m_redLED.write(State::LOW);
        // Device::delay(1000);
        // m_redLED.write(State::HIGH);

        // TB0CCR1 = us_to_ticks(MAX_PULSE_US);
        // TB0CTL = TBSSEL__SMCLK | MC__UP | TBCLR;
        

        // P2DIR |= BIT6;          // P2.6 as output
        // P2SEL0 |= BIT6;         // select peripheral function (primary)
        // P2SEL1 &= ~BIT6;
        // TA1CCR0 = 20000 - 1;    // 20 ms period (1 MHz SMCLK)
        // TA1CCTL1 = OUTMOD_7;    // Reset/Set output mode
        // TA1CCR1 = 1000;         // Initial pulse = 1.0 ms (0° position)
        // TA1CTL = TASSEL_2 | MC_1; // SMCLK, Up mode

        // m_flipper.angle(FLIPPER_DOWN_ANGLE);
        // m_redLED.write(State::HIGH);
        // Device::delay(1000); // Wait for flipper to move down
        // m_flipper.angle(FLIPPER_UP_ANGLE);
        // m_redLED.write(State::LOW);

        while(true){
            m_redLED.toggle();
            runCommand(decodeCommand(m_ir.read<SIGNAL_BITS>()));
        }
    }

    Command Robot::decodeCommand(const std::bitset<SIGNAL_BITS>& p_signal){
        if(!p_signal[SIGNAL_BITS - 1] || p_signal[SIGNAL_BITS - 2]){
            return Command::NULL_COMMAND; // Invalid start bits, return null command
        }
        // Extract last 6 bits as command
        std::bitset<COMMAND_BITS> command;
        for(std::size_t index = 0; index < COMMAND_BITS; index++) {
            command[COMMAND_BITS - index - 1] = p_signal[SIGNAL_BITS - index - 1 - START_BIT_LENGTH];
        }
        return static_cast<Command>(static_cast<std::uint8_t>(command.to_ulong()));
    }

    void Robot::configureServo(){
        // --- Servo PWM on P1.6 = TA0.1 ---
        P1DIR  |= BIT6;                // P1.6 as output
        P1SEL0 |= BIT6;                // Select TA0.1 function
        P1SEL1 |= BIT6;                // (TA0.1 is the tertiary function on P1.6)

        // --- Timer0_A setup for ~20 ms period (50 Hz) ---
        // Assume SMCLK ≈ 1 MHz (default DCO)
        TA0CCR0  = 20000 - 1;          // 20,000 counts = 20 ms
        TA0CCTL1 = OUTMOD_7;           // Reset/Set PWM mode
        TA0CCR1  = 1100;               // 1.0 ms pulse (~0°)
        TA0CTL   = TASSEL_2 | MC_1 | TACLR;   // SMCLK, up mode, clear TAR
    }

    void Robot::runCommand(const Command p_command){
        switch(p_command){
            // Left motor commands
            case Command::LEFT_STOP: {
                m_left.stop();
                return;
            }case Command::LEFT_FORWARD_25: {
                m_left.drive(25);
                return;
            }case Command::LEFT_FORWARD_50: {
                m_left.drive(50);
                return;
            }case Command::LEFT_FORWARD_75: {
                m_left.drive(75);
                return;
            }case Command::LEFT_FORWARD_100: {
                m_left.drive(100);
                return;
            }case Command::LEFT_REVERSE_25: {
                m_left.drive(-25);
                return;
            }case Command::LEFT_REVERSE_50: {
                m_left.drive(-50);
                return;
            }case Command::LEFT_REVERSE_75: {
                m_left.drive(-75);
                return;
            }case Command::LEFT_REVERSE_100: {
                m_left.drive(-100);
                return;
            }
            // Right motor commands
            case Command::RIGHT_STOP: {
                m_right.stop();
                return;
            }case Command::RIGHT_FORWARD_25: {
                m_right.drive(25);
                return;  
            }case Command::RIGHT_FORWARD_50: {
                m_right.drive(50);
                return;
            }case Command::RIGHT_FORWARD_75: {
                m_right.drive(75);
                return;
            }case Command::RIGHT_FORWARD_100: {
                m_right.drive(100);
                return;
            }case Command::RIGHT_REVERSE_25: {
                m_right.drive(-25);
                return;
            }case Command::RIGHT_REVERSE_50: {
                m_right.drive(-50);
                return;
            }case Command::RIGHT_REVERSE_75: {
                m_right.drive(-75);
                return;
            }case Command::RIGHT_REVERSE_100: {
                m_right.drive(-100);
                return;
            }
            // Flipper commands
            case Command::FLIPPER_UP: {
                TA0CCR1 = 1800;
                return;
            }case Command::FLIPPER_DOWN: {
                TA0CCR1 = 1100;
                return;
            }
            // Unrecognized command
            default: { 
                // m_leds[0].write(State::HIGH);
                // m_leds[1].write(State::HIGH);
                // m_leds[2].write(State::HIGH);
                // m_leds[3].write(State::HIGH);
                // m_leds[4].write(State::HIGH);
                return;
            }
        }
    }

} // #end: robot