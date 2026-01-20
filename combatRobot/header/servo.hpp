#include "combatRobot.hpp" // Project header file
#include "pins.hpp"
#include <cstdint>

namespace combatRobot::servo{ // #scope: servo

    constexpr float MIN_ANGLE     = 0.0f;
    constexpr float MAX_ANGLE     = 180.0f;
    constexpr float MIN_PULSE_MS  = 1.0f;   // 1.0 ms -> 0 degrees
    constexpr float MAX_PULSE_MS  = 2.0f; 
    constexpr uint16_t DEFAULT_FREQUENCY = 100; // 100 Hz

    class Servo final{
    public:
    // Public Factory Methods
        Servo(const Port p_signal, std::uint16_t p_frequency = DEFAULT_FREQUENCY);
        ~Servo() = default;
    // Public Methods
        void angle(const float p_angle);
    private:
    // Private Members
        Pin<Mode::PWM> m_signal;
    };

} // #end: servo