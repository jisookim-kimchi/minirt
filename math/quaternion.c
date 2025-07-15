#include "../include/mathheader.h"

t_quaternion init_quaternion()
{
    t_quaternion quaternion;

    quaternion.x = 0.f;
    quaternion.y = 0.f;
    quaternion.z = 0.f;
    quaternion.w = 1.f;
    return quaternion;
}

t_quaternion quaternion_constructor(float inx, float iny, float inz, float inw)
{
    t_quaternion quaternion;
    quaternion.x = inx;
    quaternion.y = iny;
    quaternion.z = inz;
    quaternion.w = inw;
    return quaternion;
}




