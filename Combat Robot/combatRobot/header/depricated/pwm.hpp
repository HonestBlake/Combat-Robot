#pragma once 

#include "combatRobot.hpp" // Project header file
#include "pins.hpp"

namespace msp430{ // #scope: msp430

    class PWM final{
    public:
    // Public Factory Methods
        PWM(const Port p_port);
        PWM(const Port p_port, const std::uint16_t p_frequency, const std::uint8_t p_dutyCycle);
    // Public Methods
        void frequency(std::uint16_t p_frequency);
        void dutyCycle(std::uint8_t p_dutyCycle);
        void start();
        void stop();
    private:
    // Private Methods
        void configureTimer();
        static std::uint16_t getTimerClearBitMask(Port p_port);
    // Private Members
        std::uint16_t m_frequency;
        std::uint8_t m_dutyCycle;
        Port m_port;
    };

} // #end: msp430