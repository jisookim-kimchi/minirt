#include "mathheader.h"

/*
	 The 'is_point' flag determines the w component:
    - If is_point is true (non-zero), w is set to 1.0 (represents a point).
    - If is_point is false (zero), w is set to 0.0 (represents a direction vector)
*/
t_vec4 vec4(float in_x, float in_y, float in_z, float is_point)
{
    t_vec4 vec4;

    vec4.x = in_x;
    vec4.y = in_y;
    vec4.z = in_z;
    vec4.w = is_point? 1.f : 0.f;

    return (vec4);
}

t_vec4 vec4_from_vec3(t_vec3 vec3, int is_point)
{
	t_vec4 vec4;

	vec4.x = vec3.x;
	vec4.y = vec3.y;
	vec4.z = vec3.z;
	vec4.w = is_point? 1.f : 0.f;

	return (vec4);
}

t_vec3 vec4_to_vec3(t_vec4 vec4)
{
	t_vec3	vec3;

	vec3.x = vec4.x;
	vec3.y = vec4.y;
	vec3.z = vec4.z;

	return (vec3);
}

float	vec4_size(t_vec4 v)
{
	return (sqrtf(vec4_size_squared(v)));
}

float	vec4_size_squared(t_vec4 v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
}


float	vec4_dot(t_vec4 a, t_vec4 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w);
}


