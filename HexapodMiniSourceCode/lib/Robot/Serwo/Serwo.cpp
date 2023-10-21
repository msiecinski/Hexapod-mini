#include "Serwo.hpp"
#include <iterator>
#define _USE_MATH_DEFINES
#include <math.h>

std::vector<std::pair<uint32_t,uint32_t>> Serwo::pwm; //first pin, second duty


Serwo::Serwo()
{
    Timer3.initialize(PWMTIMEBASE);
    Timer3.attachInterrupt(PWM50Hz); 
}

void Serwo::attach(uint32_t pin)
{
    pwm.push_back(std::make_pair(pin,int {}));
}

void Serwo::attach(std::array<uint32_t,18> pin)
{
      for(auto tmp:pin)
        pwm.push_back(std::make_pair(tmp,int {}));
}

void Serwo::PWM50Hz(void)
{   
    static volatile uint32_t counter = 0;

    if(counter < (1))
		counter++;
	else
    {
		counter = 0;
        for(auto tmp:pwm)
        {
            digitalWrite(tmp.first, HIGH);
        }
    }
    if(counter < (LIMITHI+1))   //skip all by~87.5% time(17.5ms)
    {   
        for(auto tmp:pwm)
        {
            if (counter == tmp.second)
            {
                digitalWrite(tmp.first, LOW);
            }
        }
    }
}

void Serwo::setAngle(uint32_t angle,uint32_t joint,uint32_t type )
{
    /*
        Function AngleToDuty convert calculate angles to
        duty value for pwm singnal
        100=0.5ms 
        20/9-"equivalent" 0.45 degress
        if angle <0 - duty lovest work value duty = 100
        if >180 deg duty = 500
        else calculate
       // else  convert angle too duty and cut if>512(0x1FF)
    */
   if(type == 1)
        angle *= (180 / M_PI);
    pwm[joint].second = (angle<0) ? 100 : (angle>180) ? 500 : ((uint32_t)((angle*20/9)+100)); 
}