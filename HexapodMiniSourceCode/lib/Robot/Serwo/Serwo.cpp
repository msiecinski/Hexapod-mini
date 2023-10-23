#include "Serwo.hpp"
#include <iterator>
#include <utility>

std::vector<std::pair<uint32_t,uint32_t>> Serwo::pwm; //first pin, second duty

Serwo::Serwo()
{
    Timer3.initialize(PWMTIMEBASE);
    Timer3.attachInterrupt(PWM50Hz); 
}

void Serwo::attach(uint32_t pin)
{
    pwm.push_back(std::make_pair(pin,int {}));
    pinMode(pin,OUTPUT);
}

void Serwo::attach(std::array<uint32_t,18> pin)
{
      for(auto tmp:pin)
      {
        pwm.push_back(std::make_pair(tmp,int {}));
        pinMode(tmp,OUTPUT);
      }
}

void Serwo::PWM50Hz(void)
{   
    static volatile uint32_t counter = 0;

    if(counter < (INTERRUPTCOUNTER))
		counter++;
	else
    {
		counter = 0;
        for(auto tmp:pwm)
        {
            digitalWrite(tmp.first, HIGH);
        }
    }
    if(counter < (SERWOMAXDUTY+1))   //skip all by~90% time(18.0ms)
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

void Serwo::setAngle(uint32_t angle,uint32_t joint,bool type )
{
    /*
        Function AngleToDuty convert calculate angles to
        duty value for pwm singnal
        100=0.5ms 
        10/9-"equivalent" 0.90 degress
        if angle <0 - duty lovest work value duty = 200
        if >180 deg duty = 400
        else calculate
       convert angle too duty and cut if>402(0x1FF)
    */
   if(type != false)
        angle *= (RADT0DEG);
    pwm[joint].second = (angle<SERWOMINDEGREES) ? SERWOMINDUTY   : (angle>SERWOMAXDEGREES) ? SERWOMAXDUTY : ((uint32_t)((angle*RESOLUTION)+SERWOMINDUTY)); 
}