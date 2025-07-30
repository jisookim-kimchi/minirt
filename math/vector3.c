#include "mathheader.h"

t_vec3  vec3_one()
{
    return (t_vec3){1.f, 1.f, 1.f};
}

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

// t_color3	color3(double x, double y, double z)
// {
// 	t_color3	color3;

// 	color3.x = x;
// 	color3.y = y;
// 	color3.z = z;

// 	return (color3);
// }

void	vec3_set(t_vec3 *vec3, double x, double y, double z)
{
	vec3->x = x;
	vec3->y = y;
	vec3->z = z;
}

// void	color_set(t_color_float *color3, double x, double y, double z)
// {
// 	color3->x = x;
// 	color3->y = y;
// 	color3->z = z;
// }

void	color_float_set(t_color_float *color3, float in_red, float in_green, float in_blue)
{
	color3->red = in_red;
	color3->green = in_green;
	color3->blue = in_blue;
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

//vector length (size)
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

t_vec3	vec3_plus_vec3(t_vec3 vec1, t_vec3 vec2)
{
    vec1.x += vec2.x;
    vec1.y += vec2.y;
    vec1.z += vec2.z;
    return (vec1);
}

t_vec3      vec3_sub(t_vec3 vec, double x, double y, double z)
{
    vec.x -= x;
    vec.y -= y;
    vec.z -= z;
    return (vec);
}

t_vec3      vec3_sub_vec3(t_vec3 vec1, t_vec3 vec2)
{
    vec1.x -= vec2.x;
    vec1.y -= vec2.y;
    vec1.z -= vec2.z;
    return (vec1);
}

t_vec3      vec3_multiply(t_vec3 vec, double t)
{
    vec.x *= t;
    vec.y *= t;
    vec.z *= t;
    return (vec);
}

t_vec3      vec3_multiply_vec3(t_vec3 vec1, t_vec3 vec2)
{
    vec1.x *= vec2.x;
    vec1.y *= vec2.y;
    vec1.z *= vec2.z;
    return (vec1);
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
t_vec3	vec3_normalized(t_vec3 vec3)
{
	double len;
	
	len = vec3_length(vec3);
	printf("len: %f\n", len);
	if (len < EPSILON)
	{
		printf("vec3_normalized: length is 0, cannot normalize %f\n", len);
		exit(1);
	}
	vec3.x = vec3.x / len;
	vec3.y = vec3.y / len;
	vec3.z = vec3.z / len;
	return vec3;
}

t_color_float color_float_multiply(t_color_float color, double t)
{
    t_color_float   result;
    
    result.red = color.red * t;
    result.green = color.green * t;
    result.blue = color.blue * t;
    return (result);
}

t_color3 color_float_to_col3(t_color_float input)
{
    t_color3    col3;

    col3.x = (double)input.red;
    col3.y = (double)input.green;
    col3.z = (double)input.blue;
    return (col3);
}

t_color_float color_col3_to_float(t_color3 input)
{
    t_color_float   col_float;

    col_float.red = (float)input.x;
    col_float.green = (float)input.y;
    col_float.blue = (float)input.z;
    return (col_float);
}
