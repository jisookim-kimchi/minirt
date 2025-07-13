#include "mathheader.h"

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

t_quaternion quat_from_axis_angle(t_vec3 axis, float degree)
{
    float angle_rad = deg2rad(degree) * 0.5f;
    float s = sinf(angle_rad);

    t_quaternion q;
    q.w = cosf(angle_rad);
    q.x = axis.x * s;
    q.y = axis.y * s;
    q.z = axis.z * s;
    return q;
}
