#include "pins.hpp" // Module header file
#include "combatRobot.hpp"
#include "device.hpp"

namespace combatRobot::pins{ // #scope: pins

// #scope: port

    volatile std::uint8_t& port::getDirectionRegister(const Port p_port){
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
        }else{
            Device::raiseError();
            return P1DIR; // Never reached
        }
    }

    volatile std::uint8_t& port::getOutputRegister(const Port p_port){
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
        }else{
            Device::raiseError();
        }
        return P1OUT; // Never reached
    }

    volatile std::uint8_t& port::getSelect0Register(const Port p_port){
        if(isPort1(p_port)){
            return P1SEL0;
        }else if(isPort2(p_port)){
            return P2SEL0;
        }else if(isPort3(p_port)){
            return P3SEL0;
        }else if(isPort4(p_port)){
            return P4SEL0;
        }else if(isPort5(p_port)){
            return P5SEL0;
        }else if(isPort6(p_port)){
            return P6SEL0;
        }else if(isPort7(p_port)){
            return P7SEL0;
        }else if(isPort8(p_port)){
            return P8SEL0;
        }else if(isPort9(p_port)){
            return P9SEL0;
        }else if(isPort10(p_port)){
            return P10SEL0;
        }else{
            Device::raiseError();
        }
        return P1SEL0; // Never reached
    }

    volatile std::uint8_t& port::getSelect1Register(const Port p_port){
        if(isPort1(p_port)){
            return P1SEL1;
        }else if(isPort2(p_port)){
            return P2SEL1;
        }else if(isPort3(p_port)){
            return P3SEL1;
        }else if(isPort4(p_port)){
            return P4SEL1;
        }else if(isPort5(p_port)){
            return P5SEL1;
        }else if(isPort6(p_port)){
            return P6SEL1;
        }else if(isPort7(p_port)){
            return P7SEL1;
        }else if(isPort8(p_port)){
            return P8SEL1;
        }else if(isPort9(p_port)){
            return P9SEL1;
        }else if(isPort10(p_port)){
            return P10SEL1;
        }else {
            Device::raiseError();
        }
        return P1SEL1; // Never reached
    }

    bool port::isPort1(const Port p_port){
        return (p_port >= Port::P1_0 && p_port <= Port::P1_7);
    }

    bool port::isPort2(const Port p_port){
        return (p_port >= Port::P2_0 && p_port <= Port::P2_7);
    }

    bool port::isPort3(const Port p_port){
        return (p_port >= Port::P3_0 && p_port <= Port::P3_7);
    }

    bool port::isPort4(const Port p_port){
        return (p_port >= Port::P4_0 && p_port <= Port::P4_7);
    }

    bool port::isPort5(const Port p_port){
        return (p_port >= Port::P5_0 && p_port <= Port::P5_7);
    }

    bool port::isPort6(const Port p_port){
        return (p_port >= Port::P6_0 && p_port <= Port::P6_7);
    }

    bool port::isPort7(const Port p_port){
        return (p_port >= Port::P7_0 && p_port <= Port::P7_7);
    }

    bool port::isPort8(const Port p_port){
        return (p_port >= Port::P8_0 && p_port <= Port::P8_7);
    }

    bool port::isPort9(const Port p_port){
        return (p_port >= Port::P9_0 && p_port <= Port::P9_7);
    }

    bool port::isPort10(const Port p_port){
        return (p_port >= Port::P10_0 && p_port <= Port::P10_7);
    }

    std::uint8_t port::getPort1BitMask(const Port p_port){
        switch(p_port){
            case Port::P1_0: return BIT0;
            case Port::P1_1: return BIT1;
            case Port::P1_2: return BIT2;
            case Port::P1_3: return BIT3;
            case Port::P1_4: return BIT4;
            case Port::P1_5: return BIT5;
            case Port::P1_6: return BIT6;
            case Port::P1_7: return BIT7;
            default: {
                Device::raiseError();
            }
        }
        return 0; // Never reached
    }

    std::uint8_t port::getPort2BitMask(const Port p_port){
        switch(p_port){
            case Port::P2_0: return BIT0;
            case Port::P2_1: return BIT1;
            case Port::P2_2: return BIT2;
            case Port::P2_3: return BIT3;
            case Port::P2_4: return BIT4;
            case Port::P2_5: return BIT5;
            case Port::P2_6: return BIT6;
            case Port::P2_7: return BIT7;
            default: {
                Device::raiseError();
            }
        }
        return 0; // Never reached
    }

    std::uint8_t port::getPort3BitMask(const Port p_port){
        switch(p_port){
            case Port::P3_0: return BIT0;
            case Port::P3_1: return BIT1;
            case Port::P3_2: return BIT2;
            case Port::P3_3: return BIT3;
            case Port::P3_4: return BIT4;
            case Port::P3_5: return BIT5;
            case Port::P3_6: return BIT6;
            case Port::P3_7: return BIT7;
            default: {
                Device::raiseError();
            }
        }
        return 0; // Never reached
    }

    std::uint8_t port::getPort4BitMask(const Port p_port){
        switch(p_port){
            case Port::P4_0: return BIT0;
            case Port::P4_1: return BIT1;
            case Port::P4_2: return BIT2;
            case Port::P4_3: return BIT3;
            case Port::P4_4: return BIT4;
            case Port::P4_5: return BIT5;
            case Port::P4_6: return BIT6;
            case Port::P4_7: return BIT7;
            default: {
                Device::raiseError();
            }
        }
        return 0; // Never reached
    }

    std::uint8_t port::getPort5BitMask(const Port p_port){
        switch(p_port){
            case Port::P5_0: return BIT0;
            case Port::P5_1: return BIT1;
            case Port::P5_2: return BIT2;
            case Port::P5_3: return BIT3;
            case Port::P5_4: return BIT4;
            case Port::P5_5: return BIT5;
            case Port::P5_6: return BIT6;
            case Port::P5_7: return BIT7;
            default: {
                Device::raiseError();
            }
        }
        return 0; // Never reached
    }

    std::uint8_t port::getPort6BitMask(const Port p_port){
        switch(p_port){
            case Port::P6_0: return BIT0;
            case Port::P6_1: return BIT1;
            case Port::P6_2: return BIT2;
            case Port::P6_3: return BIT3;
            case Port::P6_4: return BIT4;
            case Port::P6_5: return BIT5;
            case Port::P6_6: return BIT6;
            case Port::P6_7: return BIT7;
            default: {
                Device::raiseError();
            }
        }
        return 0; // Never reached
    }

    std::uint8_t port::getPort7BitMask(const Port p_port){
        switch(p_port){
            case Port::P7_0: return BIT0;
            case Port::P7_1: return BIT1;
            case Port::P7_2: return BIT2;
            case Port::P7_3: return BIT3;
            case Port::P7_4: return BIT4;
            case Port::P7_5: return BIT5;
            case Port::P7_6: return BIT6;
            case Port::P7_7: return BIT7;
            default: {
                Device::raiseError();
            }
        }
        return 0; // Never reached
    }

    std::uint8_t port::getPort8BitMask(const Port p_port){
        switch(p_port){
            case Port::P8_0: return BIT0;
            case Port::P8_1: return BIT1;
            case Port::P8_2: return BIT2;
            case Port::P8_3: return BIT3;
            case Port::P8_4: return BIT4;
            case Port::P8_5: return BIT5;
            case Port::P8_6: return BIT6;
            case Port::P8_7: return BIT7;
            default: {
                Device::raiseError();
            }
        }
        return 0; // Never reached
    }

    std::uint8_t port::getPort9BitMask(const Port p_port){
        switch(p_port){
            case Port::P9_0: return BIT0;
            case Port::P9_1: return BIT1;
            case Port::P9_2: return BIT2;
            case Port::P9_3: return BIT3;
            case Port::P9_4: return BIT4;
            case Port::P9_5: return BIT5;
            case Port::P9_6: return BIT6;
            case Port::P9_7: return BIT7;
            default: {
                Device::raiseError();
            }
        }
        return 0; // Never reached
    }

    std::uint8_t port::getPort10BitMask(const Port p_port){
        switch(p_port){
            case Port::P10_0: return BIT0;
            case Port::P10_1: return BIT1;
            case Port::P10_2: return BIT2;
            case Port::P10_3: return BIT3;
            case Port::P10_4: return BIT4;
            case Port::P10_5: return BIT5;
            case Port::P10_6: return BIT6;
            case Port::P10_7: return BIT7;
            default: {
                Device::raiseError();
            }
        }
        return 0; // Never reached
    }

    std::uint8_t port::getBitMask(const Port p_port){
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
        }else{
            Device::raiseError();
        }
        return 0; // Never reached
    }

    std::uint16_t port::getTimerClearBitMask(Port p_port){
        switch(p_port){
            case Port::P2_1: return TBCLR;
            case Port::P2_7: return TBCLR;
            case Port::P2_6: return TBCLR;
            case Port::P3_3: return TACLR;
            case Port::P3_6: return TBCLR;
            default: {
                Device::raiseError();
            }
        }
        return 0; // Never reached
    }

// #scope: Pin<Mode::OUTPUT>

// Public Factory Methods

    Pin<Mode::OUTPUT>::Pin(const Port p_port): m_port(p_port){
        setOutput(p_port);
    }

    Pin<Mode::OUTPUT>::Pin(const Port p_port, const State p_state): m_port(p_port){
        setOutput(p_port);
        write(p_state);
    }

// Public Methods

    Pin<Mode::OUTPUT>& Pin<Mode::OUTPUT>::write(const State p_state){
        if(p_state == State::HIGH){
            port::getOutputRegister(m_port) |= port::getBitMask(m_port);
        }else if(p_state == State::LOW){
            port::getOutputRegister(m_port) &= ~port::getBitMask(m_port);
        }
        return *this;
    }

    Pin<Mode::OUTPUT>& Pin<Mode::OUTPUT>::toggle(){
        port::getOutputRegister(m_port) ^= port::getBitMask(m_port);
        return *this;
    }

    const Pin<Mode::OUTPUT>& Pin<Mode::OUTPUT>::write(const State p_state)const{
        if(p_state == State::HIGH){
            port::getOutputRegister(m_port) |= port::getBitMask(m_port);
        }else if(p_state == State::LOW){
            port::getOutputRegister(m_port) &= ~port::getBitMask(m_port);
        }
        return *this;
    }

   const Pin<Mode::OUTPUT>& Pin<Mode::OUTPUT>::toggle()const{
        port::getOutputRegister(m_port) ^= port::getBitMask(m_port);
        return *this;
    }

// Private Static Methods

    void Pin<Mode::OUTPUT>::setOutput(const Port p_port){
        port::getDirectionRegister(p_port) |= port::getBitMask(p_port);
    }

// #scope: Pin<Mode::PWM>

// Public Factory Methods

    Pin<Mode::PWM>::Pin(const Port p_port): m_port(p_port){
        setPWM(p_port);
    }

    Pin<Mode::PWM>::Pin(const Port p_port, const std::uint32_t p_frequency): m_port(p_port), m_frequency(p_frequency){
        setPWM(p_port);
        frequency(p_frequency);
    }

    Pin<Mode::PWM>::Pin(const Port p_port, const std::uint32_t p_frequency, const std::uint8_t p_dutyCycle): m_port(p_port), m_frequency(p_frequency), m_dutyCycle(p_dutyCycle){
        setPWM(p_port);
        frequency(p_frequency);
        dutyCycle(p_dutyCycle);
    }

// Public Methods

    Pin<Mode::PWM>& Pin<Mode::PWM>::frequency(const std::uint32_t p_frequency){
        if(!m_isRunning){
            return setFrequency(p_frequency); // Just change frequency if not running
        }
        setFrequency(p_frequency);
        std::uint16_t periodTicks = SMCLK / m_frequency; // Assuming SMCLK is 1MHz
        switch(m_port){
            case Port::P2_1: {
                TB0CCR0 = periodTicks - 1; // Set period
                break;
            }case Port::P2_7: {
                TB0CCR0 = periodTicks - 1; // Set period
                break;
            }case Port::P2_6: {
                TB0CCR0 = periodTicks - 1; // Set period
                break;
            }case Port::P3_3: {
                TA1CCR0 = periodTicks - 1; // Set period
                break;
            }case Port::P3_6: {
                TB0CCR0 = periodTicks - 1; // Set period
                break;
            }default: {
                Device::raiseError();
            }
        }
        return *this;
    }

    Pin<Mode::PWM>& Pin<Mode::PWM>::dutyCycle(const std::uint8_t p_dutyCycle){
        if(!m_isRunning){
            return setDutyCycle(p_dutyCycle); // Just change duty cycle if not running
        }
        setDutyCycle(p_dutyCycle);
        std::uint32_t periodTicks = SMCLK / m_frequency; // Assuming SMCLK is 1MHz
        std::uint32_t dutyTicks = (periodTicks * m_dutyCycle) / 100; // Duty cycle in ticks
        switch(m_port){
            case Port::P2_1: {
                TB0CCR1 = dutyTicks; // Set duty cycle
                break;
            }case Port::P2_7: {
                TB0CCR6 = dutyTicks; // Set duty cycle
                break;
            }case Port::P2_6: {
                TB0CCR5 = dutyTicks; // Set duty cycle
                break;
            }case Port::P3_3: {
                TA1CCR1 = dutyTicks; // Set duty cycle
                break;
            }case Port::P3_6: {
                TB0CCR2 = dutyTicks; // Set duty cycle
                break;
            }default: {
                Device::raiseError();
            }
        }
        return *this;
    }

    Pin<Mode::PWM>& Pin<Mode::PWM>::start(){
        if(m_isRunning){
            return *this; // Already running
        }
        m_isRunning = true;
        configureTimer();
        switch(m_port){
            case Port::P2_1: {
                TB0CTL = TASSEL__SMCLK | MC__UP | port::getTimerClearBitMask(m_port);
                break;
            }case Port::P2_7: {
                TB0CTL = TASSEL__SMCLK | MC__UP | port::getTimerClearBitMask(m_port);
                break;
            }case Port::P2_6: {
                TB0CTL = TASSEL__SMCLK | MC__UP | port::getTimerClearBitMask(m_port);
                break;
            }case Port::P3_3: {
                TA1CTL = TASSEL__SMCLK | MC__UP | port::getTimerClearBitMask(m_port);
                break;
            }case Port::P3_6: {
                TB0CTL = TASSEL__SMCLK | MC__UP | port::getTimerClearBitMask(m_port);
                break;
            }default: {
                Device::raiseError();
            }
        }
        return *this;
    }

    Pin<Mode::PWM>& Pin<Mode::PWM>::stop(){
        if(!m_isRunning){
            return *this; // Already stopped
        }
        m_isRunning = false;
        switch(m_port){
            case Port::P2_1: {
                TB0CTL &= ~MC_3;
                break;
            }case Port::P2_7: {
                TB0CTL &= ~MC_3;
                break;
            }case Port::P2_6: {
                TB0CTL &= ~MC_3;
                break;
            }case Port::P3_3: {
                TA1CTL &= ~MC_3;
                break;
            }case Port::P3_6: {
                TB0CTL &= ~MC_3;
                break;
            }default: {
                Device::raiseError();
            }
        }
        return *this;
    }

// Private Static Methods

    void Pin<Mode::PWM>::setPWM(const Port p_port){
        port::getDirectionRegister(p_port) |= port::getBitMask(p_port); // Set as output for PWM
        port::getSelect0Register(p_port) |= port::getBitMask(p_port); // Set function select 0 to 1
        port::getSelect1Register(p_port) &= ~port::getBitMask(p_port); // Set function select 1 to 0
    }

// Private methods

    Pin<Mode::PWM>& Pin<Mode::PWM>::setFrequency(const std::uint32_t p_frequency){
        if(p_frequency < MIN_PWM_FREQUENCY){
            m_frequency = MIN_PWM_FREQUENCY;
        }else{
            m_frequency = p_frequency;
        }
        return *this;
    }

    Pin<Mode::PWM>& Pin<Mode::PWM>::setDutyCycle(const std::uint8_t p_dutyCycle){
        if(p_dutyCycle > MAX_PWM_DUTY_CYCLE){
            m_dutyCycle = MAX_PWM_DUTY_CYCLE; // Cap at 100%
        }else{
            m_dutyCycle = p_dutyCycle;
        }
        return *this;
    }   

    void Pin<Mode::PWM>::configureTimer(){
        std::uint32_t periodTicks = SMCLK / m_frequency; // Assuming SMCLK is 1MHz
        std::uint32_t dutyTicks = (periodTicks * m_dutyCycle) / 100; // Duty cycle in ticks
        switch(m_port){
            case Port::P2_1: {
                TB0CCR0 = periodTicks - 1; // Set period
                TB0CCR1 = dutyTicks; // Set duty cycle
                TB0CCTL1 = OUTMOD_7; // Reset/Set mode
                break;
            }case Port::P2_7: {
                TB0CCR0 = periodTicks - 1; // Set period
                TB0CCR6 = dutyTicks; // Set duty cycle
                TB0CCTL6 = OUTMOD_7; // Reset/Set mode
                break;
            }case Port::P2_6: {
                TB0CCR0 = periodTicks - 1; // Set period
                TB0CCR5 = dutyTicks; // Set duty cycle
                TB0CCTL5 = OUTMOD_7; // Reset/Set mode
                break;
            }case Port::P3_3: {
                TA1CCR0 = periodTicks - 1; // Set period
                TA1CCR1 = dutyTicks; // Set duty cycle
                TA1CCTL1 = OUTMOD_7; // Reset/Set mode
                break;
            }case Port::P3_6: {
                TB0CCR0 = periodTicks - 1; // Set period
                TB0CCR2 = dutyTicks; // Set duty cycle
                TB0CCTL2 = OUTMOD_7; // Reset/Set mode
                break;
            }default: {
                Device::raiseError();
            }
        }
    }
   

} // #end: pins