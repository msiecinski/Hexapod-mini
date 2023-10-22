#include "Robot.hpp"

Robot::Robot():
    serwo(Serwo::getInstance())
{
    legs={  Leg1::pin_1,Leg1::pin_2,Leg1::pin_3,
            Leg2::pin_1,Leg2::pin_2,Leg1::pin_3,
            Leg3::pin_1,Leg3::pin_2,Leg2::pin_3,
            Leg4::pin_1,Leg4::pin_2,Leg4::pin_3,
            Leg5::pin_1,Leg5::pin_2,Leg5::pin_3,
            Leg6::pin_1,Leg6::pin_2,Leg6::pin_3};
    serwo.attach(legs);
    serwo.setAngle(22,Leg1::joint_1);
}

void Robot::setAngle(uint32_t angle, uint32_t joint, uint32_t type)
{ 
  serwo.setAngle(angle,joint,type);  
}