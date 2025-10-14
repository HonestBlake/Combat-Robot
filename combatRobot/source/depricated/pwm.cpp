#include "pwm.hpp" // Module header file

#include "device.hpp"

namespace msp430{ // #scope: msp430

// Public Factory Methods
    
    PWM::PWM(const Port p_port){
        m_port = p_port;
    }

    PWM::PWM(const Port p_port, const std::uint16_t p_frequency, const std::uint8_t p_dutyCycle){
        m_port = p_port;
        if(p_frequency == 0){
            m_frequency = 1; // Minimum frequency is 1 Hz
        }else{
            m_frequency = p_frequency;
        }
        if(p_dutyCycle > 100){
            m_dutyCycle = 100; // Cap at 100%
        }else{
            m_dutyCycle = p_dutyCycle;
        }
        start();
    }

// Public Methods

    

// Private Methods

    

    


} // #end: msp430