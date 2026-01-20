#include "remote.hpp"
#include "device.hpp"
#include "ir.hpp"
#include "pins.hpp"
#include "robotValues.hpp"
#include <bitset>

// 3.48 - 1.74 - 0

namespace combatRobot::remoteController::remote{ // #scope: remote

    Remote::Remote(): m_ir(IR_EMITTER_PORT, BIT_PERIOD, SIGNAL_FREQUENCY), m_redLED(RED_LED_PORT, State::LOW), m_greenLED(GREEN_LED_PORT, State::LOW), m_leftJoyStick(LEFT_JOYSTICK_PORT), m_rightJoyStick(RIGHT_JOYSTICK_PORT), m_flipperUp(FLIPPER_UP_PORT), m_flipperDown(FLIPPER_DOWN_PORT){
        
    }

    void Remote::run(){
        Device::stopWDT();
        Device::enableGPIO();
        m_greenLED.write(State::HIGH);
        while(true){
            handleRightJoyStick();
            handleLeftJoyStick();
            handleFlipperUp();
            handleFlipperDown();
        }
    }

// Private methods

    std::bitset<SIGNAL_BITS> Remote::encodeCommand(const Command p_command){
        std::bitset<SIGNAL_BITS> signal;
        signal[SIGNAL_BITS - 1] = START_BIT_0;
        signal[SIGNAL_BITS - 2] = START_BIT_1; 
        std::bitset<COMMAND_BITS> command = static_cast<std::bitset<COMMAND_BITS>>(static_cast<std::uint8_t>(p_command));
        for(std::size_t index = 0; index < COMMAND_BITS; index++){
            signal[SIGNAL_BITS - index - 1 - START_BIT_LENGTH] = command[COMMAND_BITS - index - 1];
        }
        return signal;
    }

    void Remote::handleLeftJoyStick(){
        static Command previous = Command::NULL_COMMAND;
        static Command current = Command::NULL_COMMAND;
        static std::uint8_t repeatCount = 0;
        float voltage = m_leftJoyStick.read();      
        if(voltage < LEFT_REVERSE_75_THRESHOLD){ // Reverse 100
            current = Command::LEFT_REVERSE_100;
        }else if(voltage < LEFT_REVERSE_50_THRESHOLD){ // Reverse 75
            current = Command::LEFT_REVERSE_75;
        }else if(voltage < LEFT_REVERSE_25_THRESHOLD){ // Reverse 50
            current = Command::LEFT_REVERSE_50;
        }else if(voltage < LEFT_STOP_THRESHOLD){ // Reverse 25
            current = Command::LEFT_REVERSE_25;
        }else if(voltage < LEFT_FORWARD_25_THRESHOLD){ // Stop
            current = Command::LEFT_STOP;
        }else if(voltage < LEFT_FORWARD_50_THRESHOLD){ // Forward 25
            current = Command::LEFT_FORWARD_25;
        }else if(voltage < LEFT_FORWARD_75_THRESHOLD){ // Forward 50
            current = Command::LEFT_FORWARD_50;
        }else if(voltage < LEFT_FORWARD_100_THRESHOLD){ // Forward 75
            current = Command::LEFT_FORWARD_75;
        }else{ // Forward 100
            current = Command::LEFT_FORWARD_100;
        }
        if(current == previous && repeatCount++ < REPEAT_LIMIT) return;
        m_ir.send<SIGNAL_BITS>(encodeCommand(current));
        Device::delay(COMMAND_DELAY); // Small delay to ensure command is sent properly
        previous = current;
        repeatCount = 0;
    }

    void Remote::handleRightJoyStick(){
        static Command previous = Command::NULL_COMMAND;
        static Command current = Command::NULL_COMMAND;
        static std::uint8_t repeatCount = 0;
        float voltage = m_rightJoyStick.read();
        if(voltage < RIGHT_REVERSE_75_THRESHOLD){ // Reverse 100
            current = Command::RIGHT_REVERSE_100;
        }else if(voltage < RIGHT_REVERSE_50_THRESHOLD){ // Reverse 75
            current = Command::RIGHT_REVERSE_75;
        }else if(voltage < RIGHT_REVERSE_25_THRESHOLD){ // Reverse 50
            current = Command::RIGHT_REVERSE_50;
        }else if(voltage < RIGHT_STOP_THRESHOLD){ // Reverse 25
            current = Command::RIGHT_REVERSE_25;
        }else if(voltage < RIGHT_FORWARD_25_THRESHOLD){ // Stop
            current = Command::RIGHT_STOP;
        }else if(voltage < RIGHT_FORWARD_50_THRESHOLD){ // Forward 25
            current = Command::RIGHT_FORWARD_25;
        }else if(voltage < RIGHT_FORWARD_75_THRESHOLD){ // Forward 50
            current = Command::RIGHT_FORWARD_50;
        }else if(voltage < RIGHT_FORWARD_100_THRESHOLD){ // Forward 75
            current = Command::RIGHT_FORWARD_75;
        }else{ // Forward 100
            current = Command::RIGHT_FORWARD_100;
        }
        if(current == previous && repeatCount++ < REPEAT_LIMIT) return;
        m_ir.send<SIGNAL_BITS>(encodeCommand(current));
        Device::delay(COMMAND_DELAY); // Small delay to ensure command is sent properly
        previous = current;
        repeatCount = 0;
    }

    void Remote::handleFlipperUp(){
        static State previous = State::LOW;
        static std::uint8_t repeatCount = 0;
        if(m_flipperUp){
            if(previous == State::HIGH && repeatCount++ < REPEAT_LIMIT) return;
            m_ir.send<SIGNAL_BITS>(encodeCommand(Command::FLIPPER_UP));
            previous = State::HIGH;
            repeatCount = 0;
        }else{
            previous = State::LOW;
        }
    }

    void Remote::handleFlipperDown(){
        static State previous = State::LOW;
        static std::uint8_t repeatCount = 0;
        if(m_flipperDown){
            if(previous == State::HIGH && repeatCount++ < REPEAT_LIMIT) return;
            m_ir.send<SIGNAL_BITS>(encodeCommand(Command::FLIPPER_DOWN));
            previous = State::HIGH;
            repeatCount = 0;
        }else{
            previous = State::LOW;
        }
    }

} // #end: remote