#include "device.hpp" // Module header file
#include "pins.hpp"
#include "motors.hpp"

namespace combatRobot::device{ // #scope: device

// Public Methods

    

// Public Static Methods

    void Device::delay(const std::uint16_t p_milliseconds){
        for (uint16_t i = 0; i < p_milliseconds; i++) {
            __delay_cycles(1'000); // 1 ms at 1 MHz
        }
    }

    void Device::raiseError(){
        Pin<Mode::OUTPUT> led = Pin<Mode::OUTPUT>(Port::P1_0, State::LOW);
        while(true){
            led.toggle();
            delay(100); // 100 ms delay
        }
    }

// Private Methods

    void Device::stopWDT(){
        WDTCTL = WDTPW | WDTHOLD; // Stop watchdog timer
    }

    void Device::enableGPIO(){
        PM5CTL0 &= ~LOCKLPM5; // Disable the GPIO power-on default high-impedance mode to activate previously configured port settings
    }

} // #end: device


