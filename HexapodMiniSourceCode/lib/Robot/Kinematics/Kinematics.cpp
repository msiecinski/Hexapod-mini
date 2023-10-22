#include "kinematics.hpp"

#define _USE_MATH_DEFINES
#include "math.h"

//#include "RobotConstans.hpp"
legAngle Kinematics::calculateAngles(legPos pos)//(leg &newpos)
{
    /*
        Function InversKinematics takes on entry position(x,y,z),   
        next calculate and return necessary angles in degrees or radians(q1,q2,q3)
    */
    double r,d;
    legAngle out;

    out._x = atan2(pos._y,pos._x);                                                            //q1 == x

    r = sqrt(pos._x * pos._x+pos._y * pos._y);
	d = (((r-A1) * (r-A1) + (pos._z-E) * (pos._z-E) - (A2*A2)-(A3*A3)) / (2*A2*A3));
    out._z = atan2(-sqrt(1-d), d);                                                                        //q3 == z

	out._y = atan2(pos._z-E, r-A1) - atan2(A3*sin(out._z), A2+A3*cos(out._z));  //q2 == y

    out._x+=rotateX;
    out._y+=rotateY;
    out._z+=rotateZ;
    if (type == false)
    {
        //convert from RAD to DEG
        out._x *= (180 / M_PI);
        out._y *= (180 / M_PI);
        out._z *= (180 / M_PI);
    }
    
    return out;
}