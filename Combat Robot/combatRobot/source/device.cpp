#include "device.hpp" // Module header file
#include "pins.hpp"
#include "motors.hpp"

namespace msp430{ // #scope: msp430

// Public Methods

    void Device::run(){
        stopWDT(); // Stop watchdog timer
        enableGPIO(); // Disable GPIO high-impedance mode
        Motor leftMotor = Motor(Port::P2_0, Port::P2_1, Port::P2_2);
        Motor rightMotor = Motor(Port::P2_3, Port::P2_4, Port::P2_5);
        while(true){
            leftMotor.drive(50); 
            rightMotor.drive(50);
            delay(1000); // Delay for 1 second
            leftMotor.stop();
            rightMotor.stop();
            delay(1000); // Delay for 1 second
            leftMotor.drive(-50);
            rightMotor.drive(-50);
            delay(1000); // Delay for 1 second
            leftMotor.stop();
            rightMotor.stop();
            delay(1000); // Delay for 1 second
            leftMotor.drive(50);
            rightMotor.drive(-50);
            delay(1000); // Delay for 1 second
            leftMotor.stop();
            rightMotor.stop();
            delay(1000); // Delay for 1 second
            leftMotor.drive(-50);
            rightMotor.drive(50);
            delay(1000); // Delay for 1 second
            leftMotor.stop();
            rightMotor.stop();
            delay(1000); // Delay for 1 second
        }
    }

// Private Methods

    void Device::stopWDT(){
        WDTCTL = WDTPW | WDTHOLD; // Stop watchdog timer
    }

    void Device::enableGPIO(){
        PM5CTL0 &= ~LOCKLPM5; // Disable the GPIO power-on default high-impedance mode to activate previously configured port settings
    }

    void Device::delay(std::uint16_t p_milliseconds){

    }
        

} // #end: msp430


