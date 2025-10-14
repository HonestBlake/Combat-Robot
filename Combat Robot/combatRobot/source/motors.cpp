#include "motors.hpp" // Module header file

namespace combatRobot::motors{ // #scope: motors

// Public Factory Methods

    Motor::Motor(Port p_in1, Port p_in2, Port p_enable):
        m_in1(Pin(p_in1, Mode::OUTPUT)),
        m_in2(Pin(p_in2, Mode::OUTPUT)),
        m_signal(Pin(p_enable, Mode::PWM, MOTOR_PWM_FREQUENCY, 0)){}
    
// Public Methods

    void Motor::drive(std::int8_t p_speed){
        if(p_speed == 0){
            m_signal.dutyCycle(0); // Stop the motor
        }else if(p_speed > 0){ // Forward Direction
            m_in1.write(IN1_MOTOR_FORWARD_STATE);
            m_in2.write(IN2_MOTOR_FORWARD_STATE);
            m_signal.dutyCycle(p_speed);
        }else if(p_speed < 0){ // Reverse Direction
            m_in1.write(IN1_MOTOR_REVERSE_STATE);
            m_in2.write(IN2_MOTOR_REVERSE_STATE);
            m_signal.dutyCycle(-p_speed);
        }
    }

    void Motor::stop(){
        drive(0);
    }

} // #end: motors