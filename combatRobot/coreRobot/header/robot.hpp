#pragma once

#include "coreRobot.hpp" // Project header file
#include "ir.hpp"
#include "motors.hpp"
#include "pins.hpp"
#include "robotValues.hpp"
#include <cstdint>

namespace combatRobot::coreRobot::robot{ // #scope: robot

    constexpr Port IR_IN = Port::P4_7;
    constexpr Port LEFT_IN1 = Port::P2_1;
    constexpr Port LEFT_IN2 = Port::P1_5;
    constexpr Port LEFT_ENA = Port::P2_7;
    constexpr Port RIGHT_IN1 = Port::P2_4;
    constexpr Port RIGHT_IN2 = Port::P2_5;
    constexpr Port RIGHT_ENA = Port::P2_6;

    // #class: Robot
    class Robot final{
    public:
    // Public Factory Methods
        Robot();
        ~Robot() = default;
    // Public Static Methods
        void run();
        static Command decodeCommand(const std::bitset<SIGNAL_BITS>& p_signal);
    // Public Methods
        void runCommand(const Command p_command);
    private:
    // Private Members
        IRReceiver m_ir = IRReceiver(IR_IN, BIT_PERIOD);
        Motor m_left, m_right;

        std::array<Pin<Mode::OUTPUT>, 8> m_leds = {
            Pin<Mode::OUTPUT>(Port::P3_3, State::LOW),
            Pin<Mode::OUTPUT>(Port::P3_6, State::LOW),
            Pin<Mode::OUTPUT>(Port::P3_7, State::LOW),
            Pin<Mode::OUTPUT>(Port::P2_2, State::LOW),
            Pin<Mode::OUTPUT>(Port::P1_3, State::LOW),
            Pin<Mode::OUTPUT>(Port::P3_0, State::LOW),
            Pin<Mode::OUTPUT>(Port::P3_1, State::LOW),
            Pin<Mode::OUTPUT>(Port::P2_3, State::LOW)
        };
    };

} // #end: robot