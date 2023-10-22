#pragma once

#include <TimerThree.h>
#include <vector>
#include <array>


//class Serwo  uses timer3

constexpr int32_t CALIBRATION       =   8; 
constexpr int32_t INTERRUPTCOUNTER  =   (4000 - CALIBRATION);   //interupt counter for 50Hz pwm
constexpr int32_t LIMITHI           =   (INTERRUPTCOUNTER/8+1); //limit for skip conditions after every 2.5ms //11 bcs of 0x1FF
constexpr int32_t PWMTIMEBASE       =   5;                      //time base for interrupts

//class Robot{};
class Serwo
{
    friend class Robot;
    private:
        static Serwo& getInstance()
        {
            static Serwo instance; 
            return instance;
        };
        void attach(std::array<uint32_t,18> pin);
        void attach(uint32_t a);
        void setAngle(uint32_t,uint32_t,bool type = false);
    private:
        Serwo();
        static void PWM50Hz(void) ;
        static std::vector<std::pair<uint32_t,uint32_t>> pwm; //first pin, second duty
};
