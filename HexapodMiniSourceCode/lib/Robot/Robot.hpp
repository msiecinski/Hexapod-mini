#pragma once
#include "Serwo/Serwo.hpp"
#include "Kinematics/kinematics.hpp"
#include "RobotConstans.hpp"
#include <array>




class Robot
{
    public:
        static Robot& getInstance()
        {
            static Robot instance; 
            return instance;
        };
        //tempolary public
        void setAngle(uint32_t angle, uint32_t joint);
    private:
        Robot();
        std::array<uint32_t,18> legs;
        const bool type;
        Serwo &serwo;
        Kinematics kinematics;
       
           
};


