#include "robot.hpp"
#include "device.hpp"
#include "pins.hpp"

namespace combatRobot::coreRobot::robot{ // #scope: robot

// Public Methods 

    void Robot::run()const{
        combatRobot::Device().run();
    }

} // #end: robot