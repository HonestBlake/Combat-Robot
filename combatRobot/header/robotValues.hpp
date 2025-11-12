#pragma once

#include "combatRobot.hpp" // Project header file
#include <map>
#include <bitset>
#include "pins.hpp"

namespace combatRobot::robotValues{ // #scope: robotValues

    inline constexpr std::uint32_t SMCLK = 1'000'000; // 1 MHz
    inline constexpr std::uint8_t BIT_PERIOD = 20; // 100 ms
    inline constexpr std::uint8_t SIGNAL_BITS = 8;
    inline constexpr std::uint16_t SIGNAL_FREQUENCY = 50'000; // 50 kHz
    inline constexpr std::uint8_t START_BIT_LENTH = 2;
    inline constexpr std::uint8_t COMMAND_BITS = 6;
    inline constexpr Port RED_LED_PORT = Port::P1_0;
    inline constexpr Port GREEN_LED_PORT = Port::P9_7;
    enum class Command: std::uint8_t{
        // Left motor commands
        LEFT_STOP = 0x000001,
        LEFT_FORWARD_25 = 0b000010,
        LEFT_FORWARD_50 = 0b000011,
        LEFT_FORWARD_75 = 0b000100,
        LEFT_FORWARD_100 = 0b000101,
        LEFT_REVERSE_25 = 0b000110,
        LEFT_REVERSE_50 = 0b000111,
        LEFT_REVERSE_75 = 0b001000,
        LEFT_REVERSE_100 = 0b001001,
        // Right motor commands
        RIGHT_STOP = 0b001010,
        RIGHT_FORWARD_25 = 0b001011,
        RIGHT_FORWARD_50 = 0b001100,
        RIGHT_FORWARD_75 = 0b001101,
        RIGHT_FORWARD_100 = 0b001110,
        RIGHT_REVERSE_25 = 0b001111,
        RIGHT_REVERSE_50 = 0b010000,
        RIGHT_REVERSE_75 = 0b010001,
        RIGHT_REVERSE_100 = 0b010010,
        // Null command
        NULL_COMMAND = 0b111111
    };

} // #end: robotValues