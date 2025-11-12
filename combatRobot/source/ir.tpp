#pragma once

#include "ir.hpp" // Module header file
#include "device.hpp" // For Device class

namespace combatRobot::ir{ // #scope: ir

// #from: IRReceiver

// Public Methods

    template<std::uint8_t t_bits> std::bitset<t_bits> IRReceiver::read(){
        std::bitset<t_bits> bits;
        while(!m_pin);
        Device::delay(m_halfBitPeriod); // Wait half bit period
        for(std::uint8_t bitIndex = t_bits; bitIndex > 0; bitIndex--){
            bits[bitIndex - 1] = static_cast<bool>(m_pin);
            Device::delay(m_bitPeriod);
        }
        return bits;
    }

// #from: IREmitter

// Public Methods

    template<int t_bits> IREmitter& IREmitter::send(const std::bitset<t_bits>& p_bits){
        for(std::size_t index = t_bits; index > 0; index--){
            if(p_bits[index - 1]){
                m_pin.dutyCycle(IR_EMITTER_DUTY_CYCLE);
            }else{
                m_pin.stop();
            }
            Device::delay(m_bitPeriod);
        }
        m_pin.stop(); 
        return *this;
    }

} // #end: ir