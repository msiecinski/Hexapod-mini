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
    private:
        Robot();
        std::array<uint32_t,18> legs;
       
};


