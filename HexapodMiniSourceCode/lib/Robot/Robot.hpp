#pragma once
#include "Serwo/Serwo.hpp"
#include "Kinematics/kinematics.hpp"
#include "RobotConstans.hpp"
#include <array>
#include "Delay/Delay.hpp"




class Robot
{
    public:
        static Robot& getInstance()
        {
            static Robot instance; 
            return instance;
        };
        //tempolary public
        void setPosition(int32_t x, int32_t y, int32_t z,const uint32_t* joints);
    private:
        std::array<uint32_t,18> legs;
        const bool type;
        Serwo &serwo;
        Kinematics kinematics;
        Delay &delay;
       
        Robot();
        void setAngle(uint32_t angle, uint32_t joint);
        void blinkLed(int32_t counter);
};
