#pragma once

#include <msp430fr6989.h> // Device header file

#include <cstdlib> // For EXIT_SUCCESS
#include <cstdint> // For int types

#ifdef __clang__ // Manual declaration for Clangd to avoid errors not actually being used when compiling with MSP430-GCC
    extern "C" void __delay_cycles(unsigned long cycles);
#endif

// #namespace: combatRobot
namespace combatRobot{

    constexpr std::uint32_t SMCLK = 1'000'000; // 1 MHz

    // #namespace: coreRobot
    inline namespace coreRobot{
        inline namespace robot{}
    } // #end: coreRobot

    // #namespace: remoteController
    inline namespace remoteController{
        
    } // #end: remoteController

    // #namespace: device
    inline namespace device{
        class Device;
    } // #end: device

    // #namespace: pins
    inline namespace pins{
        enum class Port : std::uint8_t;
        enum class State : bool;
        enum class Mode : std::uint8_t;
        class Pin;
    } // #end: pins

    // #namespace: motors
    inline namespace motors{
        class Motor;
    } // #end: motors


} // #end: combatRobot