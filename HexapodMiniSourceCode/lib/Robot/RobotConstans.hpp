#pragma once


namespace Leg1
{
   constexpr uint32_t joint_1 = 8, joint_2 = 9, joint_3 = 10 ;
   constexpr uint32_t jo1nts[3]{joint_1,joint_2,joint_3};
};
namespace Leg2
{
   constexpr uint32_t joint_1 = 5, joint_2 = 6, joint_3 = 7;
   constexpr uint32_t jo1nts[3]{joint_1,joint_2,joint_3};
};
namespace Leg3
{
   constexpr uint32_t joint_1 = 2, joint_2 = 3, joint_3 = 4  ;
   constexpr uint32_t jo1nts[3]{joint_1,joint_2,joint_3};
 };
namespace Leg4
{
    constexpr uint32_t joint_1 = 41, joint_2 = 40, joint_3 = 39 ;
    constexpr uint32_t jo1nts[3]{joint_1,joint_2,joint_3};
 };
namespace Leg5
{
   constexpr uint32_t joint_1 = 38, joint_2 = 37, joint_3 = 36 ;
   constexpr uint32_t jo1nts[3]{joint_1,joint_2,joint_3};
 };
namespace Leg6
{
    constexpr uint32_t joint_1 = 35, joint_2 = 34, joint_3 = 33 ;
    constexpr uint32_t jo1nts[3]{joint_1,joint_2,joint_3};
};



constexpr unsigned int JOINTSNUMBER =   18;

constexpr unsigned int  A_1   =  (5);
constexpr unsigned int  A_2   =  (15);
constexpr unsigned int  A_3   =  (25);//(22);
constexpr unsigned int  E     =  (2);

#define _USE_MATH_DEFINES
#include <math.h>
  /*
        PI/2 and PI value based on set servos "0" posiotion 
    */
constexpr double rotateX=0;
constexpr double rotateY=(M_PI/2);
constexpr double rotateZ=M_PI;
constexpr bool   DEG =  false;
constexpr bool   RAD =  true;
