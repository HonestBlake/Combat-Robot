#pragma once

#include "combatRobot.hpp" // Project header file

namespace combatRobot::pins{ // #scope: pins

    // #enum: Mode, Enum Class
    enum class Mode: std::uint8_t{ 
        OUTPUT, 
        INPUT,
        PWM
    }; // #end: Mode

    // #enum: State, Enum Class
    enum class State: bool{ 
        HIGH = 1, 
        LOW = 0 
    }; // #end: State

    // #enum: Port, Enum Class
    enum class Port: std::uint8_t{
        P1_0, P1_1, P1_2, P1_3, P1_4, P1_5, P1_6, P1_7,
        P2_0, P2_1, P2_2, P2_3, P2_4, P2_5, P2_6, P2_7,
        P3_0, P3_1, P3_2, P3_3, P3_4, P3_5, P3_6, P3_7,
        P4_0, P4_1, P4_2, P4_3, P4_4, P4_5, P4_6, P4_7,
        P5_0, P5_1, P5_2, P5_3, P5_4, P5_5, P5_6, P5_7,
        P6_0, P6_1, P6_2, P6_3, P6_4, P6_5, P6_6, P6_7,
        P7_0, P7_1, P7_2, P7_3, P7_4, P7_5, P7_6, P7_7,
        P8_0, P8_1, P8_2, P8_3, P8_4, P8_5, P8_6, P8_7,
        P9_0, P9_1, P9_2, P9_3, P9_4, P9_5, P9_6, P9_7,
        P10_0, P10_1, P10_2, P10_3, P10_4, P10_5, P10_6, P10_7
    }; // #end: Port

    // #class: Pin
    class Pin final{
    public:
    // Public Factory Methods
        Pin(const Port p_pin);
        Pin(const Port p_pin, const Mode p_mode);
        Pin(const Port p_pin, const Mode p_mode, const State p_state);
        Pin(const Port p_port, const Mode p_mode, const std::uint16_t p_frequency, const std::uint8_t p_dutyCycle);
    // Public Methods
        Pin& write(const State p_state);
        Pin& toggle();
        Pin& set(const Mode p_mode);
        void frequency(std::uint16_t p_frequency);
        void dutyCycle(std::uint8_t p_dutyCycle);
        void start();
        void stop();
    private:
    // Private Static Methods
        static volatile std::uint8_t& getDirectionRegister(const Port p_port);
        static volatile std::uint8_t& getOutputRegister(const Port p_port);
        static volatile std::uint8_t& getSelect0Register(const Port p_port);
        static volatile std::uint8_t& getSelect1Register(const Port p_port);
        static bool isPort1(const Port p_port);
        static bool isPort2(const Port p_port);
        static bool isPort3(const Port p_port);
        static bool isPort4(const Port p_port);
        static bool isPort5(const Port p_port);
        static bool isPort6(const Port p_port);
        static bool isPort7(const Port p_port);
        static bool isPort8(const Port p_port);
        static bool isPort9(const Port p_port);
        static bool isPort10(const Port p_port);
        static std::uint8_t getPort1BitMask(const Port p_port);
        static std::uint8_t getPort2BitMask(const Port p_port);
        static std::uint8_t getPort3BitMask(const Port p_port);
        static std::uint8_t getPort4BitMask(const Port p_port);
        static std::uint8_t getPort5BitMask(const Port p_port);
        static std::uint8_t getPort6BitMask(const Port p_port);
        static std::uint8_t getPort7BitMask(const Port p_port);
        static std::uint8_t getPort8BitMask(const Port p_port);
        static std::uint8_t getPort9BitMask(const Port p_port);
        static std::uint8_t getPort10BitMask(const Port p_port);
        static std::uint8_t getBitMask(const Port p_port); 
        static std::uint16_t getTimerClearBitMask(Port p_port);
    // Private Methods
        void configureTimer();
    // Private Members
        Port m_port;
        std::uint16_t m_frequency;
        std::uint8_t m_dutyCycle;
    }; // #end: Pin

} // #end: pins