#ifndef MATHHEADER_H
# define MATHHEADER_H

# include <math.h>
# include "../MLX42/include/MLX42/MLX42.h"
# include <assert.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

# define EPSILON 0.00001

//typedef struct s_vec3 t_vec3;
typedef struct s_vec3 t_point3;
// typedef struct s_vec3 t_color3;

typedef struct s_color_float
{
	float	red;
	float	green;
	float	blue;
}	t_color_float;

typedef struct s_color_32
{
	uint32_t	red;
	uint32_t	green;
	uint32_t	blue;
	uint32_t	alpha;
	uint32_t	result_color;
}	t_color_32;

//vector_struct.h
typedef struct s_vec4
{
	float x;
	float y;
	float z;
	float w;
}	t_vec4;

typedef struct s_vec2
{
	float x;
	float y;
}	t_vec2;

// change it later double to float
typedef struct s_vec3
{
	double x;
	double y;
	double z;
}	t_vec3;

typedef struct s_canvas
{
	int	width;
	int	height;
} t_canvas;

typedef struct s_ray
{
	t_point3 orign;
	t_vec3   dir;
} t_ray;

typedef struct s_quaternion
{
    float   x;
    float   y;
    float   z;
    float   w;
} t_quaternion;

typedef struct s_transform
{
    t_vec3          position;
    t_quaternion    rotation;
    t_vec3          scale;
}   t_transform;

typedef struct s_rotator
{
    float yaw;
    float roll;
    float pitch;
} t_rotator;

/*
    aspectratio = x / y
*/
typedef struct s_screenpoint
{
    int     x;
    int     y;
    float   aspect_ratio;
} t_screenpoint;

//quaternion.c
t_quaternion init_quaternion();

//screen.c
t_screenpoint make_screen(int in_x, int in_y);
float   get_screen_aspect_ratio(t_screenpoint *screen);

//rotator.c
t_rotator init_rotator();
t_rotator constructor( float in_yaw, float in_pitch, float in_roll);
float clamp_axis(float angle);
void clamp(t_rotator *rotator);
void get_local_axes(const t_rotator* rot, t_vec3* outRight, t_vec3* outUp, t_vec3* outForward);

//mathutils.c
float deg2rad(float indegree);

//transform.c
t_transform init_transform(void);


t_vec3		vec3(double x, double y, double z);
t_vec3		vec3_one();
t_point3	point3(double x, double y, double z);
t_color_float	color3(double x, double y, double z);
void		vec3_set(t_vec3 *vec3, double x, double y, double z);
// void		color_set(t_color_float *color3, double x, double y, double z);
void		color_float_set(t_color_float *color3, float in_red, float in_green, float in_blue);
void		point_set(t_point3 *point3, double x, double y, double z);
double		vec3_length_squared(t_vec3 vec);
double      vec3_length(t_vec3 vec);
t_vec3		vec3_add(t_vec3 vec, double x, double y, double z);
t_vec3		vec3_plus_vec3(t_vec3 vec1, t_vec3 vec2);
t_vec3      vec3_sub(t_vec3 vec, double x, double y, double z);
t_vec3      vec3_sub_vec3(t_vec3 vec1, t_vec3 vec2);
t_vec3      vec3_multiply(t_vec3 vec, double t);
t_vec3      vec3_multiply_vec3(t_vec3 vec1, t_vec3 vec2);
t_vec3      vec3_divide(t_vec3 vec, double t);
double		vec3_dot(t_vec3 vec1, t_vec3 vec2);
t_vec3		vec3_cross(t_vec3 vec1, t_vec3 vec2);
t_vec3		vec3_normalized(t_vec3 vec3);

//vector4.c
t_vec4 vec4(float x, float y, float z, float w);
t_vec4 vec4_from_vec3(t_vec3 v3, int is_point);

//t_vec4 vec4_from_vec2(t_vec2 v2, int is_point);
//t_vec2 vec4_to_vec2(t_vec4 v4);
t_vec3 vec4_to_vec3(t_vec4 v4);
float	vec4_size(t_vec4 v);
float	vec4_size_squared(t_vec4 v);
float	vec4_dot(t_vec4 a, t_vec4 b);

t_vec4	vec4_add(t_vec4 a, t_vec4 b);
t_vec4	vec4_sub(t_vec4 a, t_vec4 b);
t_vec4	vec4_mul(t_vec4 a, float scale);
t_vec4	vec4_div(t_vec4 a, float scale);

t_vec4	vec4_negate(t_vec4 v);
t_vec4	vec4_normalize(t_vec4 v);
int		vec4_equals_tol(t_vec4 a, t_vec4 b, float tolerance);
float	vec4_max_component(t_vec4 v);

//trace.c
t_point3    ray_at(t_ray *ray, double t);
t_ray       ray(t_point3 orig, t_vec3 dir);

extern const t_vec4 VEC4_ZERO;
extern const t_vec4 VEC4_ONE;
extern const t_vec4 VEC4_UNIT_X;
extern const t_vec4 VEC4_UNIT_Y;
extern const t_vec4 VEC4_UNIT_Z;
extern const t_vec4 VEC4_UNIT_W;

#endif