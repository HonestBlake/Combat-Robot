#include "pins.hpp" // Module header file
#include "combatRobot.hpp"
#include "device.hpp"

#include "robotValues.hpp"

namespace combatRobot::pins{ // #scope: pins

// #scope: port

    volatile std::uint8_t& port::directionRegister(const Port p_port){
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

    volatile std::uint8_t& port::outputRegister(const Port p_port){
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

    volatile std::uint8_t& port::inputRegister(const Port p_port){
        if(isPort1(p_port)){
            return P1IN;
        }else if(isPort2(p_port)){
            return P2IN;
        }else if(isPort3(p_port)){
            return P3IN;
        }else if(isPort4(p_port)){
            return P4IN;
        }else if(isPort5(p_port)){
            return P5IN;
        }else if(isPort6(p_port)){
            return P6IN;
        }else if(isPort7(p_port)){
            return P7IN;
        }else if(isPort8(p_port)){
            return P8IN;
        }else if(isPort9(p_port)){
            return P9IN;
        }else if(isPort10(p_port)){
            return P10IN;
        }else{
            Device::raiseError();
        }
        return P1IN; // Never reached
    }

    volatile std::uint8_t& port::pullRegister(const Port p_port){
        if(isPort1(p_port)){
            return P1REN;
        }else if(isPort2(p_port)){
            return P2REN;
        }else if(isPort3(p_port)){
            return P3REN;
        }else if(isPort4(p_port)){
            return P4REN;
        }else if(isPort5(p_port)){
            return P5REN;
        }else if(isPort6(p_port)){
            return P6REN;
        }else if(isPort7(p_port)){
            return P7REN;
        }else if(isPort8(p_port)){
            return P8REN;
        }else if(isPort9(p_port)){
            return P9REN;
        }else if(isPort10(p_port)){
            return P10REN;
        }else{
            Device::raiseError();
        }
        return P1REN; // Never reached
    }

    volatile std::uint8_t& port::select0Register(const Port p_port){
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

    volatile std::uint8_t& port::select1Register(const Port p_port){
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

    std::uint8_t port::port1BitMask(const Port p_port){
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

    std::uint8_t port::port2BitMask(const Port p_port){
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

    std::uint8_t port::port3BitMask(const Port p_port){
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

    std::uint8_t port::port4BitMask(const Port p_port){
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

    std::uint8_t port::port5BitMask(const Port p_port){
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

    std::uint8_t port::port6BitMask(const Port p_port){
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

    std::uint8_t port::port7BitMask(const Port p_port){
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

    std::uint8_t port::port8BitMask(const Port p_port){
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

    std::uint8_t port::port9BitMask(const Port p_port){
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

    std::uint8_t port::port10BitMask(const Port p_port){
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

    std::uint8_t port::bitMask(const Port p_port){
        if(isPort1(p_port)){
            return port1BitMask(p_port);
        }else if(isPort2(p_port)){
            return port2BitMask(p_port);
        }else if(isPort3(p_port)){
            return port3BitMask(p_port);
        }else if(isPort4(p_port)){
            return port4BitMask(p_port);
        }else if(isPort5(p_port)){
            return port5BitMask(p_port);
        }else if(isPort6(p_port)){
            return port6BitMask(p_port);
        }else if(isPort7(p_port)){
            return port7BitMask(p_port);
        }else if(isPort8(p_port)){
            return port8BitMask(p_port);
        }else if(isPort9(p_port)){
            return port9BitMask(p_port);
        }else if(isPort10(p_port)){
            return port10BitMask(p_port);
        }else{
            Device::raiseError();
        }
        return 0; // Never reached
    }

    std::uint16_t port::timerClearBitMask(Port p_port){
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

    std::uint16_t port::adcChannel(const Port p_port){
        switch(p_port){
            case Port::P9_2: return ADC12INCH_10;
            case Port::P9_3: return ADC12INCH_11;
            case Port::P8_4: return ADC12INCH_7;
            case Port::P8_5: return ADC12INCH_6;
            case Port::P8_6: return ADC12INCH_5;
            case Port::P8_7: return ADC12INCH_4;
            case Port::P9_0: return ADC12INCH_8;
            case Port::P9_1: return ADC12INCH_9;
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
            port::outputRegister(m_port) |= port::bitMask(m_port);
        }else if(p_state == State::LOW){
            port::outputRegister(m_port) &= ~port::bitMask(m_port);
        }
        return *this;
    }

    Pin<Mode::OUTPUT>& Pin<Mode::OUTPUT>::toggle(){
        port::outputRegister(m_port) ^= port::bitMask(m_port);
        return *this;
    }

    const Pin<Mode::OUTPUT>& Pin<Mode::OUTPUT>::write(const State p_state)const{
        if(p_state == State::HIGH){
            port::outputRegister(m_port) |= port::bitMask(m_port);
        }else if(p_state == State::LOW){
            port::outputRegister(m_port) &= ~port::bitMask(m_port);
        }
        return *this;
    }

   const Pin<Mode::OUTPUT>& Pin<Mode::OUTPUT>::toggle()const{
        port::outputRegister(m_port) ^= port::bitMask(m_port);
        return *this;
    }

// Private Static Methods

    void Pin<Mode::OUTPUT>::setOutput(const Port p_port){
        port::directionRegister(p_port) |= port::bitMask(p_port);
    }

// #from: Pin<Mode::Input>

// Public factory methods

    Pin<Mode::INPUT>::Pin(const Port p_port): m_port(p_port){
        setInput(p_port);
    }

    Pin<Mode::INPUT>::Pin(const Port p_port, const Pull p_state): m_port(p_port){
        setInput(p_port);
        pull(p_state);
    }

// Public Operators

    Pin<Mode::INPUT>::operator bool()const{
        return read() == State::HIGH? true: false;
    }

    bool Pin<Mode::INPUT>::operator!()const{
        return !(read() == State::HIGH? true: false);
    }

// Private Static Methods

    void Pin<Mode::INPUT>::setInput(const Port p_port){
        port::directionRegister(p_port) &= ~port::bitMask(p_port);
    }

    void Pin<Mode::INPUT>::enablePull(const Port p_port){
        port::pullRegister(p_port) |= port::bitMask(p_port); // Enable pull resistor
    }

// Public methods

    State Pin<Mode::INPUT>::read()const{
        if(port::inputRegister(m_port) & port::bitMask(m_port)) return State::HIGH;
        else return State::LOW;
    }

    const Pin<Mode::INPUT>& Pin<Mode::INPUT>::pull(const Pull p_pull){
        enablePull(m_port);
        if(p_pull == Pull::UP){
            port::outputRegister(m_port) |= port::bitMask(m_port);
        }else{
            port::outputRegister(m_port) &= ~port::bitMask(m_port);
        }
        return *this;
    }

// #from: Pin<Mode::PWM>

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

    Pin<Mode::PWM>& Pin<Mode::PWM>::enable(){
        if(m_isRunning){
            return *this; // Already running
        }
        m_isRunning = true;
        configureTimer();
        switch(m_port){
            case Port::P2_1: {
                TB0CTL = TASSEL__SMCLK | MC__UP | port::timerClearBitMask(m_port);
                break;
            }case Port::P2_7: {
                TB0CTL = TASSEL__SMCLK | MC__UP | port::timerClearBitMask(m_port);
                break;
            }case Port::P2_6: {
                TB0CTL = TASSEL__SMCLK | MC__UP | port::timerClearBitMask(m_port);
                break;
            }case Port::P3_3: {
                TA1CTL = TASSEL__SMCLK | MC__UP | port::timerClearBitMask(m_port);
                break;
            }case Port::P3_6: {
                TB0CTL = TASSEL__SMCLK | MC__UP | port::timerClearBitMask(m_port);
                break;
            }default: {
                Device::raiseError();
            }
        }
        return *this;
    }

    Pin<Mode::PWM>& Pin<Mode::PWM>::disable(){
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

    Pin<Mode::PWM>& Pin<Mode::PWM>::stop(){
        return dutyCycle(0);
    }

// Private Static Methods

    void Pin<Mode::PWM>::setPWM(const Port p_port){
        port::directionRegister(p_port) |= port::bitMask(p_port); // Set as output for PWM
        port::select0Register(p_port) |= port::bitMask(p_port); // Set function select 0 to 1
        port::select1Register(p_port) &= ~port::bitMask(p_port); // Set function select 1 to 0
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

// #from: Pin<Mode::ANALOG>

// Public Factory Methods

    Pin<Mode::ANALOG>::Pin(const Port p_port): m_port(p_port){
        setAnalog(p_port);
        configureADC();
    }

// Public Methods

    std::uint16_t Pin<Mode::ANALOG>::readRaw()const{
        clearENC(); // Clear ENC before changing settings
        ADC12MCTL0 = port::adcChannel(m_port); // Select Channel, Use the header macros: ADC12MCTL0 = ADC12INCH_x
        // Clear any stale IFG if header defines it
        #ifdef ADC12IFG
            ADC12IFG = 0;
        #endif
        // Start conversion
        ADC12CTL0 |= ADC12ENC; // Set ENC 
        ADC12CTL0 |= ADC12SC; // Set SC
        std::uint16_t timeout = 10000; // Timeout to prevent infinite loop
        while((ADC12CTL1 & ADC12BUSY) && timeout-- > 0); // Wait for conversion to complete. ADC12BUSY is set while conversion is active.
        if(timeout == 0){   
            Device::raiseError(); // Timeout occurred
        }
        uint16_t raw = static_cast<uint16_t>(ADC12MEM0 & ADC12_MAX_VALUE); // Read result (12-bit)
        clearENC(); // Clear ENC after reading
        return raw;
    }

    float Pin<Mode::ANALOG>::read()const{
        return static_cast<float>(readRaw()) * (VCC / static_cast<float>(ADC12_MAX_VALUE)); 
    }
    
// Private Static Methods

    void Pin<Mode::ANALOG>::setAnalog(const Port p_port){
        port::directionRegister(p_port) &= ~port::bitMask(p_port); // Set as input for analog
        port::pullRegister(p_port) &= ~port::bitMask(p_port); // Disable pull resistor
        port::outputRegister(p_port) &= ~port::bitMask(p_port); // Set output low
        port::select0Register(p_port) |= port::bitMask(p_port); // Set function select 0 to 1
        port::select1Register(p_port) |= port::bitMask(p_port); // Set function select 1 to 1
    }
    
    void Pin<Mode::ANALOG>::clearENC(){
        ADC12CTL0 &= ~ADC12ENC;
    }

    void Pin<Mode::ANALOG>::configureADC(){
        static bool isConfigured = false;
        if(isConfigured){
            return; // Already configured
        }
        ADC12CTL0 = ADC12SHT0_3 | ADC12ON; // set sampling time | turn on ADC12
        ADC12CTL1 = ADC12SHP | ADC12SSEL_3; // Use sampling timer, SMCLK
        ADC12CTL2 = ADC12RES_2; // 12-bit conversion results
        ADC12CTL0 &= ~ADC12SC; // Ensure ADC is not sampling
        // Clear/disable per-memory flags if available (optional & conditional)
        #ifdef ADC12IFG
            ADC12IFG = 0;
        #endif
        #ifdef ADC12IE
            ADC12IE = 0;
        #endif
        isConfigured = true;
    }

} // #end: pins
    