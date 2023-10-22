#include "Robot.hpp"

Robot::Robot():
    type(DEG),
    serwo(Serwo::getInstance()),
    kinematics{A_1,A_2,A_3,E,rotateX,rotateY,rotateZ,type}
{
    legs={  Leg1::pin_1,Leg1::pin_2,Leg1::pin_3,
            Leg2::pin_1,Leg2::pin_2,Leg1::pin_3,
            Leg3::pin_1,Leg3::pin_2,Leg2::pin_3,
            Leg4::pin_1,Leg4::pin_2,Leg4::pin_3,
            Leg5::pin_1,Leg5::pin_2,Leg5::pin_3,
            Leg6::pin_1,Leg6::pin_2,Leg6::pin_3};
    serwo.attach(legs);
 }

void Robot::setAngle(uint32_t angle, uint32_t joint)
{ 
  serwo.setAngle(angle,joint,type);  
}

void Robot::setPosition(int32_t x, int32_t y, int32_t z,const uint32_t* joints)
{
  legAngle tmp = kinematics.calculateAngles({x,y,z});
  setAngle(tmp._x,joints[0]);
  setAngle(tmp._y,joints[1]);
  setAngle(tmp._z,joints[2]);
}
