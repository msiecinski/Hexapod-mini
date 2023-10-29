#include "Delay.hpp"

std::vector<std::function<void(uint32_t)>> Delay::funcs;

Delay::Delay()
{
    Timer1.initialize(DELAYTIMER1);
    Timer1.attachInterrupt(delayFuncExe); 
}

void Delay::delayFuncExe()
{
    static uint32_t counter =0;
    for(auto  tmp:funcs)
    {
        tmp(counter);
    }
    counter++;
}

void Delay::attach(std::function<void(uint32_t)> func)
{
    funcs.push_back(func);
}