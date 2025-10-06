#pragma once

#include "combatRobot.hpp" // Project header file

namespace msp430{ // #namespace: msp430

    // #class: Device
    class Device{
    public:
    // Public Methods
        void run();
    private:
    // Private Methods
        void stopWDT();
        void enableGPIO();
        void delay(std::uint16_t p_milliseconds);
    }; // #end: Device

} // #end: msp430