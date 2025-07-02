#include "struct.h"

t_vec3	vec3(double x, double y, double z)
{
    t_vec3	vec;

    vec.x = x;
    vec.y = y;
    vec.z = z;
    
	return (vec);
}

t_point3	point3(double x, double y, double z)
{
	t_point3	point;
	
	point.x = x;
	point.y = y;
	point.z = z;
	
	return (point);
}
t_color3	color3(double x, double y, double z)
{
	t_color3	color3;

	color3.x = x;
	color3.y = y;
	color3.z = z;

	return (color3);
}

void	vec_set(t_vec3 *vec3, double x, double y, double z)
{
	vec3->x = x;
	vec3->y = y;
	vec3->z = z;
}

void	color_set(t_color3 *color3, double x, double y, double z)
{
	color3->x = x;
	color3->y = y;
	color3->z = z;
}

void	point_set(t_point3 *point3, double x, double y, double z)
{
	point3->x = x;
	point3->y = y;
	point3->z = z;
}
//vector len squared
double	vec3_length_squared(t_vec3 vec)
{
    return (vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

//vector length
double      vec3_length(t_vec3 vec)
{
    return (sqrt(vec3_length_squared(vec)));
}

t_vec3	vec3_add(t_vec3 vec, double x, double y, double z)
{
    vec.x += x;
    vec.y += y;
    vec.z += z;
    return (vec);
}

t_vec3      vec3_sub(t_vec3 vec, double x, double y, double z)
{
    vec.x -= x;
    vec.y -= y;
    vec.z -= z;
    return (vec);
}

t_vec3      vec3_multiply(t_vec3 vec, double t)
{
    vec.x *= t;
    vec.y *= t;
    vec.z *= t;
    return (vec);
}
t_vec3      vec3_divide(t_vec3 vec, double t)
{
    vec.x *= 1 / t;
    vec.y *= 1 / t;
    vec.z *= 1 / t;

    return vec;
}

//vector dot
double	vec3_dot(t_vec3 vec1, t_vec3 vec2)
{
    return (vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z);
}

//vector cross
t_vec3	vec3_cross(t_vec3 vec1, t_vec3 vec2)
{
    t_vec3 new;

    new.x = vec1.y * vec2.z - vec1.z * vec2.y;
    new.y = vec1.z * vec2.x - vec1.x * vec2.z;
    new.z = vec1.x * vec2.y - vec1.y * vec2.x;
    return (new);
}

//get unit vector
t_vec3	vec3_unit(t_vec3 vec3)
{
	double len = vec3_length(vec3);
	if (len == 0.0)
	{
		printf("vec3_unit cant be divided\n");
		exit(0);
	}
	vec3.x = vec3.x / len;
	vec3.y = vec3.y / len;
	vec3.z = vec3.z / len;
	return vec3;
}
