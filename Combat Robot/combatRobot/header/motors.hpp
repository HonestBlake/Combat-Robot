#pragma once

#include "combatRobot.hpp" // Project header file
#include "pins.hpp" // For Pin class

namespace combatRobot::motors{ // #scope: motors

    constexpr std::uint16_t MOTOR_PWM_FREQUENCY = 1'000; // Hz
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
    // Private Members
        Pin m_in1, m_in2, m_signal; // Motor control pins 
    }; // #end: Motor

} // #end: motors