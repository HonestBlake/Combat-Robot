#pragma once

#include "combatRobot.hpp" // Project header file
#include "pins.hpp" // For Pin class
#include <bitset> // For std::bitset

namespace combatRobot::ir{ // #scope: ir

    constexpr std::uint8_t IR_EMITTER_DUTY_CYCLE = 50; // 50% duty cycle
    constexpr std::uint8_t BIT_PERIOD_DELAY = 0;

    // #class: IRReceiver
    class IRReceiver final{
    public:
    // Public Factory Methods
        IRReceiver(const Port p_port);
    // Public Methods
        
    private:
    // Private Members
        // Pin<Mode::ANALOG> m_pin;
    }; // #end: IRReceiver

    // #class: IREmitter
    class IREmitter final{
    public:
    // Public Factory Methods
        IREmitter(const Port p_port);
        IREmitter(const Port p_port, const std::uint8_t p_bitPeriod);
        IREmitter(const Port p_port, const std::uint8_t p_bitPeriod, const std::uint32_t p_frequency);
    // Public Methods
        IREmitter& frequency(const std::uint32_t p_frequency); 
        IREmitter& bitPeriod(const std::uint8_t p_bitPeriod);
        IREmitter& sendBit(const bool p_bit);
        template<int t_bits> IREmitter& sendBitStream(const std::bitset<t_bits>& p_bits);
    private:
    // Private Members
        Pin<Mode::PWM> m_pin;
        std::uint8_t m_bitPeriod; // Time for each bit in microseconds
        std::uint32_t m_frequency; // Frequency in Hz
    }; // #end: IREmitter


} // #end: ir