#include "pins.hpp" // Module header file

namespace msp430{ // #scope: msp430

// Public Factory Methods

    Pin::Pin(const Port p_port){
        m_port = p_port;
    }

    Pin::Pin(const Port p_port, const Mode p_mode){
        m_port = p_port;
        set(p_mode);
    }

    Pin::Pin(const Port p_port, const Mode p_mode, const State p_state){
        m_port = p_port;
        set(p_mode);
        write(p_state);
    }

// Public Methods

    Pin& Pin::write(const State p_state){
        if(p_state == State::HIGH){
            getOutputRegister(m_port) |= getBitMask(m_port);
        }else if(p_state == State::LOW){
            getOutputRegister(m_port) &= ~getBitMask(m_port);
        }
        return *this;
    }

    Pin& Pin::toggle(){
        getOutputRegister(m_port) ^= getBitMask(m_port);
        return *this;
    }

    Pin& Pin::set(const Mode p_mode){
        if(p_mode == Mode::OUTPUT){
            getDirectionRegister(m_port) |= getBitMask(m_port);
        }else if(p_mode == Mode::INPUT){
            getDirectionRegister(m_port) &= ~getBitMask(m_port);
        }
        return *this;
    }

// Private Static Methods

    volatile std::uint8_t& Pin::getDirectionRegister(const Port p_port){
        if(isPort1(p_port)){
            return P1DIR;
        }else if(isPort2(p_port)){
            return P2DIR;
        }else if(isPort3(p_port)){
            return P3DIR;
        }else if(isPort4(p_port)){
            return P4DIR;
        }else if(isPort5(p_port)){
            return P5DIR;
        }else if(isPort6(p_port)){
            return P6DIR;
        }else if(isPort7(p_port)){
            return P7DIR;
        }else if(isPort8(p_port)){
            return P8DIR;
        }else if(isPort9(p_port)){
            return P9DIR;
        }else if(isPort10(p_port)){
            return P10DIR;
        }
        return P1DIR; // Default return this is an error
    }

    volatile std::uint8_t& Pin::getOutputRegister(const Port p_port){
        if(isPort1(p_port)){
            return P1OUT;
        }else if(isPort2(p_port)){
            return P2OUT;
        }else if(isPort3(p_port)){
            return P3OUT;
        }else if(isPort4(p_port)){
            return P4OUT;
        }else if(isPort5(p_port)){
            return P5OUT;
        }else if(isPort6(p_port)){
            return P6OUT;
        }else if(isPort7(p_port)){
            return P7OUT;
        }else if(isPort8(p_port)){
            return P8OUT;
        }else if(isPort9(p_port)){
            return P9OUT;
        }else if(isPort10(p_port)){
            return P10OUT;
        }
        return P1OUT; // Default return this is an error
    }

    bool Pin::isPort1(const Port p_port){
        return (p_port >= Port::P1_0 && p_port <= Port::P1_7);
    }

    bool Pin::isPort2(const Port p_port){
        return (p_port >= Port::P2_0 && p_port <= Port::P2_7);
    }

    bool Pin::isPort3(const Port p_port){
        return (p_port >= Port::P3_0 && p_port <= Port::P3_7);
    }

    bool Pin::isPort4(const Port p_port){
        return (p_port >= Port::P4_0 && p_port <= Port::P4_7);
    }

    bool Pin::isPort5(const Port p_port){
        return (p_port >= Port::P5_0 && p_port <= Port::P5_7);
    }

    bool Pin::isPort6(const Port p_port){
        return (p_port >= Port::P6_0 && p_port <= Port::P6_7);
    }

    bool Pin::isPort7(const Port p_port){
        return (p_port >= Port::P7_0 && p_port <= Port::P7_7);
    }

    bool Pin::isPort8(const Port p_port){
        return (p_port >= Port::P8_0 && p_port <= Port::P8_7);
    }

    bool Pin::isPort9(const Port p_port){
        return (p_port >= Port::P9_0 && p_port <= Port::P9_7);
    }

    bool Pin::isPort10(const Port p_port){
        return (p_port >= Port::P10_0 && p_port <= Port::P10_7);
    }

    std::uint8_t Pin::getPort1BitMask(const Port p_port){
        switch(p_port){
            case Port::P1_0: return BIT0;
            case Port::P1_1: return BIT1;
            case Port::P1_2: return BIT2;
            case Port::P1_3: return BIT3;
            case Port::P1_4: return BIT4;
            case Port::P1_5: return BIT5;
            case Port::P1_6: return BIT6;
            case Port::P1_7: return BIT7;
            default: return 0; // Default return this is an error
        }
    }

    std::uint8_t Pin::getPort2BitMask(const Port p_port){
        switch(p_port){
            case Port::P2_0: return BIT0;
            case Port::P2_1: return BIT1;
            case Port::P2_2: return BIT2;
            case Port::P2_3: return BIT3;
            case Port::P2_4: return BIT4;
            case Port::P2_5: return BIT5;
            case Port::P2_6: return BIT6;
            case Port::P2_7: return BIT7;
            default: return 0; // Default return this is an error
        }
    }

    std::uint8_t Pin::getPort3BitMask(const Port p_port){
        switch(p_port){
            case Port::P3_0: return BIT0;
            case Port::P3_1: return BIT1;
            case Port::P3_2: return BIT2;
            case Port::P3_3: return BIT3;
            case Port::P3_4: return BIT4;
            case Port::P3_5: return BIT5;
            case Port::P3_6: return BIT6;
            case Port::P3_7: return BIT7;
            default: return 0; // Default return this is an error
        }
    }

    std::uint8_t Pin::getPort4BitMask(const Port p_port){
        switch(p_port){
            case Port::P4_0: return BIT0;
            case Port::P4_1: return BIT1;
            case Port::P4_2: return BIT2;
            case Port::P4_3: return BIT3;
            case Port::P4_4: return BIT4;
            case Port::P4_5: return BIT5;
            case Port::P4_6: return BIT6;
            case Port::P4_7: return BIT7;
            default: return 0; // Default return this is an error
        }
    }

    std::uint8_t Pin::getPort5BitMask(const Port p_port){
        switch(p_port){
            case Port::P5_0: return BIT0;
            case Port::P5_1: return BIT1;
            case Port::P5_2: return BIT2;
            case Port::P5_3: return BIT3;
            case Port::P5_4: return BIT4;
            case Port::P5_5: return BIT5;
            case Port::P5_6: return BIT6;
            case Port::P5_7: return BIT7;
            default: return 0; // Default return this is an error
        }
    }

    std::uint8_t Pin::getPort6BitMask(const Port p_port){
        switch(p_port){
            case Port::P6_0: return BIT0;
            case Port::P6_1: return BIT1;
            case Port::P6_2: return BIT2;
            case Port::P6_3: return BIT3;
            case Port::P6_4: return BIT4;
            case Port::P6_5: return BIT5;
            case Port::P6_6: return BIT6;
            case Port::P6_7: return BIT7;
            default: return 0; // Default return this is an error
        }
    }

    std::uint8_t Pin::getPort7BitMask(const Port p_port){
        switch(p_port){
            case Port::P7_0: return BIT0;
            case Port::P7_1: return BIT1;
            case Port::P7_2: return BIT2;
            case Port::P7_3: return BIT3;
            case Port::P7_4: return BIT4;
            case Port::P7_5: return BIT5;
            case Port::P7_6: return BIT6;
            case Port::P7_7: return BIT7;
            default: return 0; // Default return this is an error
        }
    }

    std::uint8_t Pin::getPort8BitMask(const Port p_port){
        switch(p_port){
            case Port::P8_0: return BIT0;
            case Port::P8_1: return BIT1;
            case Port::P8_2: return BIT2;
            case Port::P8_3: return BIT3;
            case Port::P8_4: return BIT4;
            case Port::P8_5: return BIT5;
            case Port::P8_6: return BIT6;
            case Port::P8_7: return BIT7;
            default: return 0; // Default return this is an error
        }
    }

    std::uint8_t Pin::getPort9BitMask(const Port p_port){
        switch(p_port){
            case Port::P9_0: return BIT0;
            case Port::P9_1: return BIT1;
            case Port::P9_2: return BIT2;
            case Port::P9_3: return BIT3;
            case Port::P9_4: return BIT4;
            case Port::P9_5: return BIT5;
            case Port::P9_6: return BIT6;
            case Port::P9_7: return BIT7;
            default: return 0; // Default return this is an error
        }
    }

    std::uint8_t Pin::getPort10BitMask(const Port p_port){
        switch(p_port){
            case Port::P10_0: return BIT0;
            case Port::P10_1: return BIT1;
            case Port::P10_2: return BIT2;
            case Port::P10_3: return BIT3;
            case Port::P10_4: return BIT4;
            case Port::P10_5: return BIT5;
            case Port::P10_6: return BIT6;
            case Port::P10_7: return BIT7;
            default: return 0; // Default return this is an error
        }
    }

    std::uint8_t Pin::getBitMask(const Port p_port){
        if(isPort1(p_port)){
            return getPort1BitMask(p_port);
        }else if(isPort2(p_port)){
            return getPort2BitMask(p_port);
        }else if(isPort3(p_port)){
            return getPort3BitMask(p_port);
        }else if(isPort4(p_port)){
            return getPort4BitMask(p_port);
        }else if(isPort5(p_port)){
            return getPort5BitMask(p_port);
        }else if(isPort6(p_port)){
            return getPort6BitMask(p_port);
        }else if(isPort7(p_port)){
            return getPort7BitMask(p_port);
        }else if(isPort8(p_port)){
            return getPort8BitMask(p_port);
        }else if(isPort9(p_port)){
            return getPort9BitMask(p_port);
        }else if(isPort10(p_port)){
            return getPort10BitMask(p_port);
        }
        return 0; // Default return this is an error
    }

} // #end: msp430