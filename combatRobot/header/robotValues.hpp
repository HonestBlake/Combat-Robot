#pragma once

#include "combatRobot.hpp" // Project header file
#include <map>
#include <bitset>
#include "pins.hpp"

namespace combatRobot::robotValues{ // #scope: robotValues

    inline constexpr std::uint32_t SMCLK = 1'000'000; // 1 MHz
    inline constexpr std::uint8_t BIT_PERIOD = 5; // 100 ms
    inline constexpr std::uint16_t SIGNAL_FREQUENCY = 38'000; // 50 kHz
    inline constexpr std::uint8_t START_BIT_LENGTH = 2;
    inline constexpr std::uint8_t COMMAND_BITS = 5;
    inline constexpr std::uint8_t SIGNAL_BITS = START_BIT_LENGTH + COMMAND_BITS;
    inline constexpr bool START_BIT_0 = 1;
    inline constexpr bool START_BIT_1 = 0;
    inline constexpr Port RED_LED_PORT = Port::P1_0;
    inline constexpr Port GREEN_LED_PORT = Port::P9_7;
    enum class Command: std::uint8_t{
        // Left motor commands
        LEFT_STOP = 0b00001,
        LEFT_FORWARD_25 = 0b00010,
        LEFT_FORWARD_50 = 0b00011,
        LEFT_FORWARD_75 = 0b00100,
        LEFT_FORWARD_100 = 0b00101,
        LEFT_REVERSE_25 = 0b00110,
        LEFT_REVERSE_50 = 0b00111,
        LEFT_REVERSE_75 = 0b01000,
        LEFT_REVERSE_100 = 0b01001,
        // Right motor commands
        RIGHT_STOP = 0b01010,
        RIGHT_FORWARD_25 = 0b01011,
        RIGHT_FORWARD_50 = 0b01100,
        RIGHT_FORWARD_75 = 0b01101,
        RIGHT_FORWARD_100 = 0b01110,
        RIGHT_REVERSE_25 = 0b01111,
        RIGHT_REVERSE_50 = 0b10000,
        RIGHT_REVERSE_75 = 0b10001,
        RIGHT_REVERSE_100 = 0b10010,
        // Flipper commands
        FLIPPER_UP = 0b10011,
        FLIPPER_DOWN = 0b10100,
        // Null command
        NULL_COMMAND = 0b11111
    };

} // #end: robotValues