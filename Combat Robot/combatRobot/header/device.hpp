#pragma once

#include "combatRobot.hpp" // Project header file

namespace combatRobot::device{ // #namespace: device

    // #class: Device
    class Device{
    public:
    // Public Methods
        void run();
    // Public Static Methods
        static void delay(const std::uint16_t p_milliseconds);
        static void raiseError();
    private:
    // Private Methods
        void stopWDT();
        void enableGPIO();
    }; // #end: Device

} // #end: device