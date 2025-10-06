#include "motors.hpp" // Module header file

namespace msp430{ // #scope: msp430

// Public Factory Methods

    Motor::Motor(Port p_in1, Port p_in2, Port p_enable):
        m_in1(Pin(p_in1, Mode::OUTPUT)),
        m_in2(Pin(p_in2, Mode::OUTPUT)),
        m_enable(Pin(p_enable, Mode::OUTPUT, State::LOW)),
        m_pwm(PWM(/*m_enable*/)){}
    
// Public Methods

    void Motor::drive(std::int8_t p_speed){
        if(p_speed == 0){
            m_pwm.setDutyCycle(0); // Stop the motor
        }else if(p_speed > 0){ // Forward Direction
            m_in1.write(IN1_MOTOR_FORWARD_STATE);
            m_in2.write(IN2_MOTOR_FORWARD_STATE);
            m_pwm.setDutyCycle(mapSpeedToDutyCycle(p_speed));
        }else if(p_speed < 0){ // Reverse Direction
            m_in1.write(IN1_MOTOR_REVERSE_STATE);
            m_in2.write(IN2_MOTOR_REVERSE_STATE);
            m_pwm.setDutyCycle(mapSpeedToDutyCycle(p_speed));
        }
    }

    void Motor::stop(){
        drive(0);
    }

// Private Methods

    std::uint8_t Motor::mapSpeedToDutyCycle(std::int8_t p_speed){
        // todo
        return 0;
    }

} // #end: msp430