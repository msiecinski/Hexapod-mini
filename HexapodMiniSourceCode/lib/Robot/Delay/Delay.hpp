#pragma once
#include <functional>
#include <TimerOne.h>
#include <vector>

constexpr uint32_t DELAYTIMER1     =    50000;                   //!!!!!!!!!!!!!!!!!!!!!!!;

class Delay
{
    public:
        static Delay& getInstance()
        {
            static Delay instance; 
            return instance;
        };
        void attach(std::function<void(uint32_t)> func);
    private:
        Delay();
        static void delayFuncExe();
        static std::vector<std::function<void(uint32_t)>> funcs;

};