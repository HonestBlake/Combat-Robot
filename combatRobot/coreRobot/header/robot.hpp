#pragma once

#include "coreRobot.hpp" // Project header file

namespace combatRobot::coreRobot::robot{ // #scope: robot

    class Robot final{
    public:
    // Public Factory Methods
        Robot() = default;
        ~Robot() = default;
    // Public Methods
        void run()const;
    private:
    };

} // #end: robot