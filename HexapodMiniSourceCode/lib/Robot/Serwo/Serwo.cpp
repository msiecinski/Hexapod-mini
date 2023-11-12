#include "Serwo.hpp"

std::map<uint32_t,uint32_t>Serwo::pwm;
Serwo::Serwo()
{
    Timer3.initialize(PWMTIMEBASE);
    Timer3.attachInterrupt(PWM50Hz); 
}

void Serwo::attach(const std::initializer_list<uint32_t> pinx)
{
    for(auto tmp:pinx)
      {
        pwm.emplace(tmp,int {});
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
    pwm[joint] = (angle<SERWOMINDEGREES) ? SERWOMINDUTY   : (angle>SERWOMAXDEGREES) ? SERWOMAXDUTY : ((uint32_t)((angle*RESOLUTION)+SERWOMINDUTY)); 
}