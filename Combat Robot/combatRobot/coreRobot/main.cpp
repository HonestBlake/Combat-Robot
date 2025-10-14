#include "coreRobot.hpp" //  Package file

#include "device.hpp"
#include "pins.hpp"
#include "motors.hpp"

int main(){
    combatRobot::Robot().run();
    return EXIT_SUCCESS;
}

/*  Wiring for Core Robot (MSP430FR6989)

    Left Motor in 1: MSP(P3.7) -> H_bridge(IN1)
    Left Motor in 2: MSP(P2.2) -> H_bridge(IN2)
    Left Motor signal: MSP(P2.6) -> H_bridge(ENA)

    Right Motor in 3: MSP(P1.5) -> H_bridge(IN3)
    Right Motor in 4: MSP(P9.4) -> H_bridge(IN4)
    Right Motor signal: MSP(P2.7) -> H_bridge(ENB1)

*/  

void combatRobot::Device::run(){
    stopWDT(); // Stop watchdog timer
    enableGPIO(); // Disable GPIO high-impedance mode
    Pin led = Pin(Port::P9_7, Mode::OUTPUT, State::LOW);

    Motor leftMotor = Motor(Port::P3_7, Port::P2_2, Port::P2_6);
    Motor rightMotor = Motor(Port::P1_5, Port::P9_4, Port::P2_7);
    
    while(true){

        led.toggle();
        delay(500); 
        led.toggle();
        delay(500);
        led.toggle();

        // Drive forward
        leftMotor.drive(50);
        rightMotor.drive(50);
        delay(5000); // 5 seconds
        leftMotor.stop();
        rightMotor.stop();
        delay(5000); // 5 seconds

        led.toggle();
        delay(500); 
        led.toggle();
        delay(500);
        led.toggle();
        delay(500);
        led.toggle();

        // Drive backward
        leftMotor.drive(-50);
        rightMotor.drive(-50);
        delay(5000); // 5 seconds
        leftMotor.stop();
        rightMotor.stop();
        delay(5000); // 5 seconds

        led.toggle();
        delay(500); 
        led.toggle();
        delay(500);
        led.toggle();
        delay(500);
        led.toggle();

        // Turn in place clockwise
        leftMotor.drive(100);
        rightMotor.drive(-100);
        delay(5000); // 5 seconds
        leftMotor.stop();
        rightMotor.stop();
        delay(5000); // 5 seconds

        led.toggle();
        delay(500); 
        led.toggle();
        delay(500);
        led.toggle();
        delay(500);
        led.toggle();

        // Turn right 
        leftMotor.drive(80);
        rightMotor.drive(20);
        delay(5000); // 5 seconds
        leftMotor.stop();
        rightMotor.stop();
        delay(5000); // 5 seconds

        led.toggle();
        delay(500);
    }
}