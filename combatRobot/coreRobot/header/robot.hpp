#pragma once

#include "coreRobot.hpp" // Project header file
#include "ir.hpp"
#include "motors.hpp"
#include "pins.hpp"
#include "robotValues.hpp"
#include <cstdint>
#include "servo.hpp"

namespace combatRobot::coreRobot::robot{ // #scope: robot

    constexpr Port IR_IN = Port::P4_7;
    constexpr Port LEFT_IN1 = Port::P2_1;
    constexpr Port LEFT_IN2 = Port::P1_5;
    constexpr Port LEFT_ENA = Port::P2_7;
    constexpr Port RIGHT_IN1 = Port::P2_4;
    constexpr Port RIGHT_IN2 = Port::P2_5;
    constexpr Port RIGHT_ENA = Port::P2_6;
    constexpr Port FLIPPER_SIGNAL = Port::P2_7; // TODO
    constexpr float FLIPPER_UP_ANGLE = 90.0f;
    constexpr float FLIPPER_DOWN_ANGLE = 0.0f;

    // #class: Robot
    class Robot final{
    public:
    // Public Factory Methods
        Robot();
        ~Robot() = default;
    // Public Static Methods
        void run();
        static Command decodeCommand(const std::bitset<SIGNAL_BITS>& p_signal);
        static void configureServo();
    // Public Methods
        void runCommand(const Command p_command);
    private:
    // Private Members
        Pin<Mode::OUTPUT> m_redLED;
        Pin<Mode::OUTPUT> m_greenLED;
        IRReceiver m_ir = IRReceiver(IR_IN, BIT_PERIOD);
        Motor m_left, m_right;
    };

} // #end: robot