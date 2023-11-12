#pragma once
#include "Serwo/Serwo.hpp"
#include "Kinematics/kinematics.hpp"
#include "RobotConstans.hpp"
#include "MPU-6050/MPU6050.hpp"
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
        const bool type;
        Serwo serwo;
        Kinematics kinematics;
        Delay delay;
        MPU6050 imu;

        Robot();
        void setAngle(uint32_t angle, uint32_t joint);
        void blinkLed(int32_t counter);
};
