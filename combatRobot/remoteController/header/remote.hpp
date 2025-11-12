#pragma once

#include "remoteController.hpp" // Package header file
#include "ir.hpp"
#include "pins.hpp"
#include "robotValues.hpp"

namespace combatRobot::remoteController::remote{ // #scope: remote

    constexpr Port IR_EMITTER_PORT = Port::P2_7;
    constexpr Port LEFT_JOYSTICK_PORT = Port::P9_2;

    class Remote{
    public:
        Remote();
        ~Remote() = default;
    // Public methods
        void run();
        std::bitset<SIGNAL_BITS> encodeCommand(const Command p_command);
    private:
    // Private members
        IREmitter m_ir;
        Pin<Mode::OUTPUT> m_redLED;
        Pin<Mode::OUTPUT> m_greenLED;
        Pin<Mode::ANALOG> m_leftJoyStick;
        // Pin<Mode::ANALOG> m_rightJoyStick;
        // Pin<Mode::INPUT> m_flipperUp;
        // Pin<Mode::INPUT> m_flipperDown;
    };

} // #end: remote

