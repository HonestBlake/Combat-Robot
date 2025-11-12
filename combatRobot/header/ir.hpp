#pragma once

#include "combatRobot.hpp" // Project header file
#include "pins.hpp" // For Pin class
#include <bitset> // For std::bitset

namespace combatRobot::ir{ // #scope: ir

    constexpr std::uint8_t IR_EMITTER_DUTY_CYCLE = 50; // 50% duty cycle
    constexpr std::uint8_t BIT_PERIOD_DELAY = 10; // Delay adjustment in milliseconds

    // #class: IRReceiver
    class IRReceiver final{
    public:
    // Public Factory Methods
        IRReceiver(const Port p_port);
        IRReceiver(const Port p_port, const std::uint8_t p_bitPeriod);
    // Public Methods
        IRReceiver& bitPeriod(const std::uint8_t p_bitPeriod);
        template<std::uint8_t t_bits> std::bitset<t_bits> read();
    private:
    // Private Members
        Pin<Mode::INPUT> m_pin;
        std::uint8_t m_bitPeriod; // Time for each bit in milliseconds
        std::uint8_t m_halfBitPeriod; // Half bit period in milliseconds
    }; // #end: IRReceiver

    // #class: IREmitter
    class IREmitter final{
    public:
    // Public Factory Methods
        IREmitter(const Port p_port);
        IREmitter(const Port p_port, const std::uint16_t p_bitPeriod);
        IREmitter(const Port p_port, const std::uint16_t p_bitPeriod, const std::uint32_t p_frequency);
    // Public Methods
        IREmitter& frequency(const std::uint32_t p_frequency); 
        IREmitter& bitPeriod(const std::uint16_t p_bitPeriod);
        template<int t_bits> IREmitter& send(const std::bitset<t_bits>& p_bits);
    public:
    // Private Members
        Pin<Mode::PWM> m_pin;
        std::uint16_t m_bitPeriod; // Time for each bit in milliseconds
        std::uint32_t m_frequency; // Frequency in Hz
    }; // #end: IREmitter


} // #end: ir

#include "ir.tpp" // Include template implementation file