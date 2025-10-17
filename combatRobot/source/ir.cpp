#include "ir.hpp" // Module header file
#include "device.hpp" // For Device class

namespace combatRobot::ir{ // #scope: ir

// #from: IREmitter

// Public Factory Methods

    IREmitter::IREmitter(const Port p_port): m_pin(p_port){
        m_pin.dutyCycle(IR_EMITTER_DUTY_CYCLE);
    }

    IREmitter::IREmitter(const Port p_port, const std::uint8_t p_bitPeriod): m_pin(p_port), m_bitPeriod(p_bitPeriod){
        m_pin.dutyCycle(IR_EMITTER_DUTY_CYCLE);
    }

    IREmitter::IREmitter(const Port p_port, const std::uint8_t p_bitPeriod, const std::uint32_t p_frequency): m_pin(p_port, p_frequency), m_bitPeriod(p_bitPeriod){
        m_pin.dutyCycle(IR_EMITTER_DUTY_CYCLE);
    }

// Public Methods

    IREmitter& IREmitter::frequency(const std::uint32_t p_frequency){
        m_pin.frequency(p_frequency);
        return *this;
    }

    IREmitter& IREmitter::bitPeriod(const std::uint8_t p_bitPeriod){
        m_bitPeriod = p_bitPeriod;
        return *this;
    }

    IREmitter& IREmitter::sendBit(const bool p_bit){
        if(p_bit){ // Send a 1 bit
            m_pin.start();
        }
        Device::delay(m_bitPeriod - BIT_PERIOD_DELAY);
        m_pin.stop(); // Ensure PWM is stopped between bits
        return *this;
    }

    template<int t_bits> IREmitter& IREmitter::sendBitStream(const std::bitset<t_bits>& p_bits){
        for(bool bit : p_bits){
            sendBit(bit);
        }
        return *this;
    }

} // #end: ir   