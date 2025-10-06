#pragma once 

#include "combatRobot.hpp" // Project header file
#include "pins.hpp"

namespace msp430{ // #scope: msp430

    class PWM final{
    public:
    // Public Factory Methods
        PWM(/*Pin& p_pin*/);
    // Public Methods
        void setDutyCycle(std::uint8_t p_dutyCycle); 
    };

} // #end: msp430