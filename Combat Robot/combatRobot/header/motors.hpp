#pragma once

#include "combatRobot.hpp" // Project header file
#include "pins.hpp" // For Pin class
#include "pwm.hpp" // For PWM class

namespace msp430{ // #scope: msp430

    constexpr std::uint16_t MOTOR_PWM_FREQUENCY = 1000; // Hz
    constexpr State IN1_MOTOR_FORWARD_STATE = State::HIGH; // IN1 pin state for forward direction
    constexpr State IN2_MOTOR_FORWARD_STATE = static_cast<State>(!static_cast<bool>(IN1_MOTOR_FORWARD_STATE)); // IN2 pin state for forward direction
    constexpr State IN1_MOTOR_REVERSE_STATE = static_cast<State>(!static_cast<bool>(IN1_MOTOR_FORWARD_STATE)); // IN1 pin state for reverse direction
    constexpr State IN2_MOTOR_REVERSE_STATE = IN1_MOTOR_FORWARD_STATE; //

    // #class: Motor
    class Motor final{
    public:
    // Public Factory Methods
        Motor(Port p_in1, Port p_in2, Port p_enable);
    // Public Methods
        void drive(std::int8_t p_speed); // Speed range: -100 to 100
        void stop();
    private:
    // Private Methods
        std::uint8_t mapSpeedToDutyCycle(std::int8_t p_speed);
    // Private Members
        Pin m_in1, m_in2, m_enable; // Motor control pins 
        PWM m_pwm; // PWM controller
    }; // #end: Motor

} // #end: msp430