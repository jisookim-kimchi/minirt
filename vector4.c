#include "vector_struct.h"

t_vec4 vec4(float in_x, float in_y, float in_z, float is_point)
{
    t_vec4 vec4;

    vec4.x = in_x;
    vec4.y = in_y;
    vec4.z = in_z;
    vec4.w = is_point? 1.f : 0.f;

    return (vec4);
}

