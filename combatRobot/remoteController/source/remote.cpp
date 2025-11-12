#include "remote.hpp"
#include "device.hpp"
#include "ir.hpp"
#include "robotValues.hpp"
#include <bitset>

// 3.48 - 1.74 - 0

namespace combatRobot::remoteController::remote{ // #scope: remote

    Remote::Remote(): m_ir(IR_EMITTER_PORT, BIT_PERIOD, SIGNAL_FREQUENCY), m_redLED(RED_LED_PORT, State::LOW), m_greenLED(GREEN_LED_PORT, State::LOW), m_leftJoyStick(LEFT_JOYSTICK_PORT){
        
    }

    void Remote::run(){
        Device::stopWDT();
        Device::enableGPIO();

        Command leftPrevCommand = Command::NULL_COMMAND;

        while(true){
            Device::delay(100);
            float voltage = m_leftJoyStick.read();
            if(voltage < 0.200f){
                // 100
                if(leftPrevCommand == Command::LEFT_FORWARD_100) continue;
                m_ir.send<SIGNAL_BITS>(encodeCommand(Command::LEFT_FORWARD_100));
                leftPrevCommand = Command::LEFT_FORWARD_100;
            }else if(voltage < 0.500f){
                // 75
                if(leftPrevCommand == Command::LEFT_FORWARD_75) continue;
                m_ir.send<SIGNAL_BITS>(encodeCommand(Command::LEFT_FORWARD_75));
                leftPrevCommand = Command::LEFT_FORWARD_75;
            }else if(voltage < 0.800f){
                // 50
                if(leftPrevCommand == Command::LEFT_FORWARD_50) continue;
                m_ir.send<SIGNAL_BITS>(encodeCommand(Command::LEFT_FORWARD_50));
                leftPrevCommand = Command::LEFT_FORWARD_50;
            }else if(voltage < 1.100f){
                // 25
                if(leftPrevCommand == Command::LEFT_FORWARD_25) continue;
                m_ir.send<SIGNAL_BITS>(encodeCommand(Command::LEFT_FORWARD_25));
                leftPrevCommand = Command::LEFT_FORWARD_25;
            }else if(voltage < 1.900f){
                // STOP
                if(leftPrevCommand == Command::LEFT_STOP) continue;
                m_ir.send<SIGNAL_BITS>(encodeCommand(Command::LEFT_STOP));
                leftPrevCommand = Command::LEFT_STOP;
            }else if(voltage < 2.400f){
                // 25
                if(leftPrevCommand == Command::LEFT_REVERSE_25) continue;
                m_ir.send<SIGNAL_BITS>(encodeCommand(Command::LEFT_REVERSE_25));
                leftPrevCommand = Command::LEFT_REVERSE_25;
            }else if(voltage < 2.700f){
                // 50
                if(leftPrevCommand == Command::LEFT_REVERSE_50) continue;
                m_ir.send<SIGNAL_BITS>(encodeCommand(Command::LEFT_REVERSE_50));
                leftPrevCommand = Command::LEFT_REVERSE_50;
            }else if(voltage < 3.000f){
                // 75
                if(leftPrevCommand == Command::LEFT_REVERSE_75) continue;
                m_ir.send<SIGNAL_BITS>(encodeCommand(Command::LEFT_REVERSE_75));
                leftPrevCommand = Command::LEFT_REVERSE_75;
            }else{
                // 100
                if(leftPrevCommand == Command::LEFT_REVERSE_100) continue;
                m_ir.send<SIGNAL_BITS>(encodeCommand(Command::LEFT_REVERSE_100));
                leftPrevCommand = Command::LEFT_REVERSE_100;
            }
        }
    }

        // Pin<Mode::OUTPUT> led1 = Pin<Mode::OUTPUT>(Port::P1_0, State::LOW);
        // Pin<Mode::OUTPUT> led2 = Pin<Mode::OUTPUT>(Port::P9_7, State::LOW);
        // Pin<Mode::INPUT> p0 = Pin<Mode::INPUT>(Port::P2_6);
        // Pin<Mode::INPUT> p1 = Pin<Mode::INPUT>(Port::P3_3);
        // Pin<Mode::INPUT> p2 = Pin<Mode::INPUT>(Port::P3_6);
        // Pin<Mode::INPUT> p3 = Pin<Mode::INPUT>(Port::P3_7);
        // Pin<Mode::INPUT> p4 = Pin<Mode::INPUT>(Port::P2_2);
        // Pin<Mode::INPUT> p5 = Pin<Mode::INPUT>(Port::P1_3);
        // Pin<Mode::INPUT> p6 = Pin<Mode::INPUT>(Port::P3_0);
        // Pin<Mode::INPUT> p7 = Pin<Mode::INPUT>(Port::P3_1);
        // Pin<Mode::INPUT> but = Pin<Mode::INPUT>(Port::P2_3);
        // std::bitset<8> bits;
        // while(true){
        //     if(but){
        //         bits[7] = static_cast<bool>(p0.read());
        //         bits[6] = static_cast<bool>(p1.read());
        //         bits[5] = static_cast<bool>(p2.read());
        //         bits[4] = static_cast<bool>(p3.read());
        //         bits[3] = static_cast<bool>(p4.read());
        //         bits[2] = static_cast<bool>(p5.read());
        //         bits[1] = static_cast<bool>(p6.read());
        //         bits[0] = static_cast<bool>(p7.read());
        //         m_ir.send<8>(bits);
        //         led1.write(State::HIGH);
        //         Device::delay(200);
        //         led1.write(State::LOW);
        //     }
        //     led2.write(State::HIGH);
        //     Device::delay(200);
        //     led2.write(State::LOW);
        //     Device::delay(500);
        // }
    // }

    std::bitset<SIGNAL_BITS> Remote::encodeCommand(const Command p_command){
        std::bitset<SIGNAL_BITS> signal;
        signal[SIGNAL_BITS - 1] = 1; // Start bit 1
        signal[SIGNAL_BITS - 2] = 0; // Start bit 2
        std::bitset<COMMAND_BITS> command = static_cast<std::bitset<COMMAND_BITS>>(static_cast<std::uint8_t>(p_command));
        for(std::size_t index = 0; index < COMMAND_BITS; index++){
            signal[SIGNAL_BITS - index - 1 - START_BIT_LENTH] = command[COMMAND_BITS - index - 1];
        }
        return signal;
    }

} // #end: remote