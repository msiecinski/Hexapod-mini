#pragma once

//enum class Leg1:    uint32_t  { joint_1 = 0, joint_2 = 1, joint_3 = 2 };
//enum class Leg2:    uint32_t  { joint_1 = 3, joint_2 = 4, joint_3 = 5 };
//enum class Leg3:    uint32_t  { joint_1 = 6, joint_2 = 7, joint_3 = 8 };
//enum class Leg4:    uint32_t  { joint_1 = 9, joint_2 = 10, joint_3 = 11 };
//enum class Leg5:    uint32_t  { joint_1 = 12, joint_2 = 13, joint_3 = 14 };
//enum class Leg6:    uint32_t  { joint_1 = 15, joint_2 = 16, joint_3 = 17 };
namespace Leg1
{
   constexpr uint32_t joint_1 = 0, joint_2 = 1, joint_3 = 2 ;
   constexpr uint32_t pin_1 = 8, pin_2 = 9, pin_3 = 10 ;
};
namespace Leg2
{
   constexpr uint32_t jjoint_1 = 3, joint_2 = 4, joint_3 = 5;
   constexpr uint32_t pin_1 = 5, pin_2 = 6, pin_3 = 7 ;
};
namespace Leg3
{
   constexpr uint32_t joint_1 = 6, joint_2 = 7, joint_3 = 8  ;
   constexpr uint32_t pin_1 = 2, pin_2 = 3, pin_3 = 4 ;
};
namespace Leg4
{
    constexpr uint32_t joint_1 = 9, joint_2 = 10, joint_3 = 11 ;
    constexpr uint32_t pin_1 = 41, pin_2 = 40, pin_3 = 39 ;
};
namespace Leg5
{
   constexpr uint32_t joint_1 = 12, joint_2 = 13, joint_3 = 14 ;
   constexpr uint32_t pin_1 = 38, pin_2 = 37, pin_3 = 36 ;
};
namespace Leg6
{
    constexpr uint32_t joint_1 = 15, joint_2 = 16, joint_3 = 17 ;
    constexpr uint32_t pin_1 = 35, pin_2 = 34, pin_3 = 33 ;
};
constexpr unsigned int JOINTSNUMBER =   18;
