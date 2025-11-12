#include "ir.hpp" // Module header file
#include "device.hpp" // For Device class

namespace combatRobot::ir{ // #scope: ir

// #from: IRReceiver

// Public Factory Methods

    IRReceiver::IRReceiver(const Port p_port): m_pin(p_port){}

    IRReceiver::IRReceiver(const Port p_port, const std::uint8_t p_bitPeriod): m_pin(p_port){
        bitPeriod(p_bitPeriod);
    }
  
// Public Methods

    IRReceiver& IRReceiver::bitPeriod(const std::uint8_t p_bitPeriod){
        m_bitPeriod = p_bitPeriod;
        m_halfBitPeriod = p_bitPeriod / 2;
        return *this;
    }

    


// #from: IREmitter

// Public Factory Methods

    IREmitter::IREmitter(const Port p_port): m_pin(p_port){
        m_pin.stop().enable();
    }

    IREmitter::IREmitter(const Port p_port, const std::uint16_t p_bitPeriod): m_pin(p_port), m_bitPeriod(p_bitPeriod){
        m_pin.stop().enable();
    }

    IREmitter::IREmitter(const Port p_port, const std::uint16_t p_bitPeriod, const std::uint32_t p_frequency): m_pin(p_port, p_frequency), m_bitPeriod(p_bitPeriod){
        m_pin.stop().enable();
    }

// Public Methods

    IREmitter& IREmitter::frequency(const std::uint32_t p_frequency){
        m_pin.frequency(p_frequency);
        return *this;
    }

    IREmitter& IREmitter::bitPeriod(const std::uint16_t p_bitPeriod){
        m_bitPeriod = p_bitPeriod;
        return *this;
    }

} // #end: ir