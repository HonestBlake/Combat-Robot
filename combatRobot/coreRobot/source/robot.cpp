#include "robot.hpp"
#include "device.hpp"
#include "pins.hpp"
#include "robotValues.hpp"

namespace combatRobot::coreRobot::robot{ // #scope: robot

// Public Factory Methods

    Robot::Robot(): m_ir(IR_IN, BIT_PERIOD), m_left(LEFT_IN1, LEFT_IN2, LEFT_ENA), m_right(RIGHT_IN1, RIGHT_IN2, RIGHT_ENA){}

// Public Methods 

    void Robot::run(){
        Device::stopWDT();
        Device::enableGPIO();

        std::bitset<SIGNAL_BITS> receivedBits = 0b10000000;;
        std::bitset<COMMAND_BITS> parsedBits;

        
        
        Pin<Mode::OUTPUT> led = Pin<Mode::OUTPUT>(Port::P9_7, State::HIGH);
        Pin<Mode::OUTPUT> led2 = Pin<Mode::OUTPUT>(Port::P1_0, State::LOW);

        while(true){
            runCommand(decodeCommand(m_ir.read<SIGNAL_BITS>()));
        }
    }

    Command Robot::decodeCommand(const std::bitset<SIGNAL_BITS>& p_signal){
        if(!p_signal[SIGNAL_BITS - 1] || p_signal[SIGNAL_BITS - 2]){
            return Command::NULL_COMMAND; // Invalid start bits, return null command
        }
        // Extract last 6 bits as command
        std::bitset<COMMAND_BITS> command;
        for(std::size_t index = 0; index < COMMAND_BITS; index++) {
            command[COMMAND_BITS - index - 1] = p_signal[SIGNAL_BITS - index - 1 - START_BIT_LENTH];
        }
        return static_cast<Command>(static_cast<std::uint8_t>(command.to_ulong()));
    }

    void Robot::runCommand(const Command p_command){
        switch(p_command){
            // Left motor commands
            case Command::LEFT_STOP: {
                m_leds[0].write(State::HIGH);
                m_leds[1].write(State::LOW);
                m_leds[2].write(State::LOW);
                m_leds[3].write(State::LOW);
                m_leds[4].write(State::LOW);
                m_leds[5].write(State::LOW);
                m_leds[6].write(State::LOW);
                m_leds[7].write(State::HIGH);
                m_left.stop();
                return;
            }case Command::LEFT_FORWARD_25: {
                m_leds[0].write(State::HIGH);
                m_leds[1].write(State::LOW);
                m_leds[2].write(State::LOW);
                m_leds[3].write(State::LOW);
                m_leds[4].write(State::LOW);
                m_leds[5].write(State::LOW);
                m_leds[6].write(State::HIGH);
                m_leds[7].write(State::LOW);
                m_left.drive(25);
                return;
            }case Command::LEFT_FORWARD_50: {
                m_leds[0].write(State::HIGH);
                m_leds[1].write(State::LOW);
                m_leds[2].write(State::LOW);
                m_leds[3].write(State::LOW);
                m_leds[4].write(State::LOW);
                m_leds[5].write(State::LOW);
                m_leds[6].write(State::HIGH);
                m_leds[7].write(State::HIGH);
                m_left.drive(50);
                return;
            }case Command::LEFT_FORWARD_75: {
                m_leds[0].write(State::HIGH);
                m_leds[1].write(State::LOW);
                m_leds[2].write(State::LOW);
                m_leds[3].write(State::LOW);
                m_leds[4].write(State::LOW);
                m_leds[5].write(State::HIGH);
                m_leds[6].write(State::LOW);
                m_leds[7].write(State::LOW);
                m_left.drive(75);
                return;
            }case Command::LEFT_FORWARD_100: {
                m_leds[0].write(State::HIGH);
                m_leds[1].write(State::LOW);
                m_leds[2].write(State::LOW);
                m_leds[3].write(State::LOW);
                m_leds[4].write(State::LOW);
                m_leds[5].write(State::HIGH);
                m_leds[6].write(State::LOW);
                m_leds[7].write(State::HIGH);
                 m_left.drive(100);
                return;
            }case Command::LEFT_REVERSE_25: {
                m_leds[0].write(State::HIGH);
                m_leds[1].write(State::LOW);
                m_leds[2].write(State::LOW);
                m_leds[3].write(State::LOW);
                m_leds[4].write(State::LOW);
                m_leds[5].write(State::HIGH);
                m_leds[6].write(State::HIGH);
                m_leds[7].write(State::LOW);
                m_left.drive(-25);
                return;
            }case Command::LEFT_REVERSE_50: {
                m_leds[0].write(State::HIGH);
                m_leds[1].write(State::LOW);
                m_leds[2].write(State::LOW);
                m_leds[3].write(State::LOW);
                m_leds[4].write(State::LOW);
                m_leds[5].write(State::HIGH);
                m_leds[6].write(State::HIGH);
                m_leds[7].write(State::HIGH);
                m_left.drive(-50);
                return;
            }case Command::LEFT_REVERSE_75: {
                m_leds[0].write(State::HIGH);
                m_leds[1].write(State::LOW);
                m_leds[2].write(State::LOW);
                m_leds[3].write(State::LOW);
                m_leds[4].write(State::HIGH);
                m_leds[5].write(State::LOW);
                m_leds[6].write(State::LOW);
                m_leds[7].write(State::LOW);
                m_left.drive(-75);
                return;
            }case Command::LEFT_REVERSE_100: {
                m_leds[0].write(State::HIGH);
                m_leds[1].write(State::LOW);
                m_leds[2].write(State::LOW);
                m_leds[3].write(State::LOW);
                m_leds[4].write(State::HIGH);
                m_leds[5].write(State::LOW);
                m_leds[6].write(State::LOW);
                m_leds[7].write(State::HIGH);
                m_left.drive(-100);
                return;
            }
            // Right motor commands
            case Command::RIGHT_STOP: {
                m_right.stop();
                return;
            }case Command::RIGHT_FORWARD_25: {
                m_right.drive(25);
                return;  
            }case Command::RIGHT_FORWARD_50: {
                m_right.drive(50);
                return;
            }case Command::RIGHT_FORWARD_75: {
                m_right.drive(75);
                return;
            }case Command::RIGHT_FORWARD_100: {
                m_right.drive(100);
                return;
            }case Command::RIGHT_REVERSE_25: {
                m_right.drive(-25);
                return;
            }case Command::RIGHT_REVERSE_50: {
                m_right.drive(-50);
                return;
            }case Command::RIGHT_REVERSE_75: {
                m_right.drive(-75);
                return;
            }case Command::RIGHT_REVERSE_100: {
                m_right.drive(-100);
                return;
            }
            // Unrecognized command
            default: { 
                return;
            }
        }
    }

} // #end: robot