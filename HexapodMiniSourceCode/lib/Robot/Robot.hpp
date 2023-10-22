#pragma once
#include "Serwo/Serwo.hpp"
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
        void setAngle(uint32_t angle, uint32_t joint, uint32_t type = 0);
    private:
        Robot();
        std::array<uint32_t,18> legs;
        Serwo &serwo;// = Serwo::getInstance();
       
};


