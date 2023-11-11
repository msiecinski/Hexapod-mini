#pragma once

#include <TimerThree.h>
#include <vector>
#include <map>
#include <array>
#include <initializer_list>
#define _USE_MATH_DEFINES
#include <math.h>


//class Serwo  uses timer3

constexpr int32_t CALIBRATION       =   8; 
constexpr int32_t INTERRUPTCOUNTER  =   (4000 - CALIBRATION);   //interupt counter for 50Hz pwm
constexpr int32_t PWMTIMEBASE       =   5;                      //time base for interrupts
constexpr int32_t SERWOMAXDEGREES   =   180; 
constexpr int32_t SERWOMINDEGREES   =   0; 
constexpr int32_t SERWOMAXDUTY      =   ((INTERRUPTCOUNTER)/10);        //2ms
constexpr int32_t SERWOMINDUTY      =   (INTERRUPTCOUNTER/20);         //1ms
constexpr double  RESOLUTION        =   ((SERWOMAXDUTY-SERWOMINDUTY)*1.0/(SERWOMAXDEGREES-SERWOMINDEGREES));     
constexpr double  RADT0DEG          =   (180 / M_PI);  


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
        template<size_t SIZE>
        void attach(std::array<uint32_t,SIZE> pins)
        {
            for(auto tmp:pins)
            {
                pwm.insert(std::make_pair(tmp,int {}));
                pinMode(tmp,OUTPUT);
            }
        };
        void attach(const std::initializer_list<uint32_t> pinx);
        void setAngle(uint32_t,uint32_t,bool type = false);
    private:
        Serwo();
        static void PWM50Hz(void) ;
        static std::map<uint32_t,uint32_t>pwm;
};
