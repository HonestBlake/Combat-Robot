#include "motors.hpp" // Module header file
#include <cstdlib>

namespace combatRobot::motors{ // #scope: motors

// Public Factory Methods

    Motor::Motor(Port p_in1, Port p_in2, Port p_enable): m_in1(Pin<Mode::OUTPUT>(p_in1)), m_in2(Pin<Mode::OUTPUT>(p_in2)), m_signal(Pin<Mode::PWM>(p_enable, MOTOR_PWM_FREQUENCY, MIN_PWM_DUTY_CYCLE)){
        m_signal.enable(); // Initialize PWM with 0% duty cycle (stopped) and start it
    }

// Public Methods

    void Motor::drive(std::int8_t p_speed){
        if(p_speed == 0){
            m_signal.dutyCycle(MIN_PWM_DUTY_CYCLE); // Stop the motor
        }else if(p_speed > 0){ // Forward Direction
            m_in1.write(IN1_MOTOR_FORWARD_STATE);
            m_in2.write(IN2_MOTOR_FORWARD_STATE);
            m_signal.dutyCycle(mapSpeedToDutyCycle(p_speed));
        }else if(p_speed < 0){ // Reverse Direction
            m_in1.write(IN1_MOTOR_REVERSE_STATE);
            m_in2.write(IN2_MOTOR_REVERSE_STATE);
            m_signal.dutyCycle(mapSpeedToDutyCycle(p_speed));
        }
    }

    void Motor::stop(){
        drive(0);
    }

// Private Static Methods

    std::uint8_t Motor::mapSpeedToDutyCycle(std::int8_t p_speed){
        // Map speed (-100 to 100) to duty cycle (20 to 100)
        return MIN_SPEED + std::abs(p_speed) * (MAX_SPEED - MIN_SPEED) / (MAX_PWM_DUTY_CYCLE - MIN_PWM_DUTY_CYCLE);
    }

} // #end: motors