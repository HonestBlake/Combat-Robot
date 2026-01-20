#pragma once

#include "remoteController.hpp" // Package header file
#include "ir.hpp"
#include "pins.hpp"
#include "robotValues.hpp"

namespace combatRobot::remoteController::remote{ // #scope: remote

    // Remote controller MSP pins
    constexpr Port IR_EMITTER_PORT = Port::P2_7;
    constexpr Port LEFT_JOYSTICK_PORT = Port::P9_2;
    constexpr Port RIGHT_JOYSTICK_PORT = Port::P9_3;
    constexpr Port FLIPPER_UP_PORT = Port::P3_3;
    constexpr Port FLIPPER_DOWN_PORT = Port::P3_6;

    // 0 (-100) .1 (-75) .3 (-50) 0.7 (-25) 1.4 (0) 1.6 (25) 2.4 (50) 2.7 (75) 3.2 (100) 3.3
    constexpr float LEFT_REVERSE_75_THRESHOLD = 0.1f;
    constexpr float LEFT_REVERSE_50_THRESHOLD = 0.3f;
    constexpr float LEFT_REVERSE_25_THRESHOLD = 0.7f;
    constexpr float LEFT_STOP_THRESHOLD = 1.4f;
    constexpr float LEFT_FORWARD_25_THRESHOLD = 1.7f;
    constexpr float LEFT_FORWARD_50_THRESHOLD = 2.4f;
    constexpr float LEFT_FORWARD_75_THRESHOLD = 2.8f;
    constexpr float LEFT_FORWARD_100_THRESHOLD = 3.2f;

    // 0 (-100) .1 (-75) .4 (-50) 0.8 (-25) 1.6 (0) 1.8 (25) 2.4 (50) 2.8 (75) 3.2 (100) 3.3
    constexpr float RIGHT_REVERSE_75_THRESHOLD = 0.1f;
    constexpr float RIGHT_REVERSE_50_THRESHOLD = 0.4f;
    constexpr float RIGHT_REVERSE_25_THRESHOLD = 0.8f;
    constexpr float RIGHT_STOP_THRESHOLD = 1.6f;
    constexpr float RIGHT_FORWARD_25_THRESHOLD = 1.8f;
    constexpr float RIGHT_FORWARD_50_THRESHOLD = 2.4f;
    constexpr float RIGHT_FORWARD_75_THRESHOLD = 2.8f;
    constexpr float RIGHT_FORWARD_100_THRESHOLD = 3.2f;

    constexpr std::uint8_t REPEAT_LIMIT = 200;
    constexpr std::uint8_t COMMAND_DELAY = 0;

    class Remote{
    public:
        Remote();
        ~Remote() = default;
    // Public methods
        void run();
    private:
    // Private methods
        std::bitset<SIGNAL_BITS> encodeCommand(const Command p_command);
        void handleLeftJoyStick();
        void handleRightJoyStick();
        void handleFlipperUp();
        void handleFlipperDown();
    // Private members
        Pin<Mode::OUTPUT> m_redLED;
        Pin<Mode::OUTPUT> m_greenLED;
        IREmitter m_ir;
        Pin<Mode::ANALOG> m_leftJoyStick;
        Pin<Mode::ANALOG> m_rightJoyStick;
        Pin<Mode::INPUT> m_flipperUp;
        Pin<Mode::INPUT> m_flipperDown;
    };

} // #end: remote

