/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathheader.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 17:44:56 by jisokim2          #+#    #+#             */
/*   Updated: 2025/09/02 17:51:41 by tfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATHHEADER_H
# define MATHHEADER_H

# include <math.h>
# include <assert.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../MLX42/include/MLX42/MLX42.h"

# define EPSILON 1e-5

typedef struct s_vec3	t_point3;
typedef struct s_vec3	t_color3;

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
	float	x;
	float	y;
	float	z;
	float	w;
}	t_vec4;

typedef struct s_vec2
{
	float	x;
	float	y;
}	t_vec2;

// change it later double to float
typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

typedef struct s_canvas
{
	int	width;
	int	height;
}	t_canvas;

typedef struct s_ray
{
	t_point3	orign;
	t_vec3		dir;
}	t_ray;

typedef struct s_transform
{
	t_vec3	position;
}	t_transform;

// typedef struct	s_quaternion
// {
//     float   x;
//     float   y;
//     float   z;
//     float   w;
// }	t_quaternion;

// typedef struct s_transform
// {
//     t_vec3          position;
//     t_quaternion    rotation;
//     t_vec3          scale;
// }   t_transform;

// typedef struct	s_rotator
// {
//     float yaw;
//     float roll;
//     float pitch;
// }	t_rotator;

//aspectratio = x / y
typedef struct s_screenpoint
{
	int		x;
	int		y;
	float	aspect_ratio;
}	t_screenpoint;

//screen.c
t_screenpoint	make_screen(int in_x, int in_y);
float			get_screen_aspect_ratio(t_screenpoint *screen);

//mathutils.c
float			deg2rad(float indegree);

//transform.c
t_transform		init_transform(void);

//vec3.c
t_vec3			vec3(double x, double y, double z);
//t_vec3			vec3_one(void);
t_point3		point3(double x, double y, double z);
t_color_float	color3(double x, double y, double z);
void			vec3_set(t_vec3 *vec3, double x, double y, double z);
void			color_float_set(t_color_float *color3,
					float in_red, float in_green, float in_blue);
t_color3		color_float_to_col3(t_color_float input);
t_color_float	color_float_add(t_color_float color1, t_color_float color2);
t_color_float	color_col3_to_float(t_color3 input);
t_color_float	color_float_multiply(t_color_float color, double t);
t_color_float	color_float_multiply_vec3(t_color_float a, t_color_float b);
t_color_float	color_float_divide(t_color_float color, double t);
void			point_set(t_point3 *point3, double x, double y, double z);
double			vec3_length_squared(t_vec3 vec);
double			vec3_length(t_vec3 vec);
t_vec3			vec3_add(t_vec3 vec, double x, double y, double z);
t_vec3			vec3_plus_vec3(t_vec3 vec1, t_vec3 vec2);
t_vec3			vec3_sub(t_vec3 vec, double x, double y, double z);
t_vec3			vec3_sub_vec3(t_vec3 vec1, t_vec3 vec2);
t_vec3			vec3_multiply(t_vec3 vec, double t);
t_vec3			vec3_multiply_vec3(t_vec3 vec1, t_vec3 vec2);
t_vec3			vec3_divide(t_vec3 vec, double t);
double			vec3_dot(t_vec3 vec1, t_vec3 vec2);
t_vec3			vec3_cross(t_vec3 vec1, t_vec3 vec2);
t_vec3			vec3_normalized(t_vec3 vec3);
t_vec3			vec3_negate(t_vec3 v);

//trace.c
t_point3		ray_at(t_ray *ray, double t);
t_ray			create_ray(t_point3 orig, t_vec3 dir);

#endif