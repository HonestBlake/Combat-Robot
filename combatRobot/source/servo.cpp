#include "servo.hpp"
#include "algorithm"

namespace combatRobot::servo{ // #scope: servo

    Servo::Servo(const Port p_signal, std::uint16_t p_frequency): m_signal(p_signal, p_frequency){
     
    }

    void Servo::angle(const float p_angle){
        float angle = std::clamp(p_angle, MIN_ANGLE, MAX_ANGLE);

        // Map angle (0-180) to pulse width (1-2 ms)
        float pulseWidth = MIN_PULSE_MS + (angle / MAX_ANGLE) * (MAX_PULSE_MS - MIN_PULSE_MS);
        const float periodMs = 1000.0f / DEFAULT_FREQUENCY;
        const float dutyFraction = pulseWidth / periodMs;
        m_signal.dutyCycle(dutyFraction * 100.0f); // Convert to percentage
    }

} // #end: servo