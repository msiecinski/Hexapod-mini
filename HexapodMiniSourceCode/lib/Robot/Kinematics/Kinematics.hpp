#pragma once

struct _3dstruct
{
     long  _x;
     long  _y;
     long  _z;
};
using legPos    =   _3dstruct;
using legAngle  =   _3dstruct;

class Kinematics
{
    public:
        Kinematics(unsigned int A1,unsigned int A2, unsigned int A3, unsigned int E, 
                    double rotateX, double rotateY, double rotateZ, unsigned int type):
            A1(A1),A2(A2),A3(A3),E(E),
            rotateX(rotateX), rotateY(rotateY), rotateZ(rotateZ),
            type(type)
            {};
        legAngle calculateAngles(legPos pos);
    private:
        const unsigned int  A1;
        const unsigned int  A2;
        const unsigned int  A3;
        const unsigned int  E;
        const double rotateX;
        const double rotateY;
        const double rotateZ;
        const unsigned int type;
};
