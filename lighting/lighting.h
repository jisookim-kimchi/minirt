/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 20:36:12 by tfarkas           #+#    #+#             */
/*   Updated: 2025/08/30 18:44:00 by tfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHTING_H
# define LIGHTING_H

# include "../object/objects.h"

/*
	The light ratio is given in 0.0 - 1.0 range	

	In the light structure the color stored in float variables, 
	because of the lighting calculations.
	In the .rt file the colors will be given in 0 - 255 int range.
	When the light color stored need to call a function which transform
	the integer value to float.

	The color_float_set function from mathheader.h can use to set float value
	for the light_color.
*/
typedef struct s_light
{
	t_vec3			light_position;
	float			light_ratio;
	t_color_float	light_color;
	bool			is_light;
}	t_light;

typedef struct s_spot_light
{
	// t_light			light;
	t_vec3			light_position;
	float			light_ratio;
	t_color_float	light_color;
	bool			is_light;
	t_vec3			direction;
	float			intensity;
	float			radius;
	float			angle;
	float			distance;
}	t_spot_light;

typedef struct s_ambient
{
	float			ambient_ratio;
	t_color_float	ambient_color;
}	t_ambient;

typedef struct s_phong_terms
{
	double			diffuse_t;
	double			specular_t;
	t_color3		ambient_color;
	t_color3		diffuse_color;
	t_color3		specular_color;
	t_color3		result;
}	t_phong_terms;

t_light			init_light(t_vec3 in_pos, float in_bright_ratio,
					t_color_float in_color);
t_ambient		init_ambient(float in_ambient_ratio, t_color_float in_color);
t_vec3			light_reflect(t_vec3 light_dir, t_vec3 normal);
double			diffuse_term(t_hit *hit, t_light *light);
double			specular_term(t_camera *camera, t_hit *hit,
					t_light *light, double shininess);

//shadow.c
bool			is_shadow(t_objs_list *object, t_light *light, t_hit *hit);

//spot_light.c
bool			is_in_spot_cone(const t_spot_light *spot, t_vec3 point);
float			spot_light_intensity_at(const t_spot_light *spot, t_vec3 point);
float			spot_light_falloff(const t_spot_light *spot, t_vec3 point);

//spot_light_utils.c
// t_spot_light	init_spot_light(t_light *light, t_vec3 direction, float distance, float angle, float intensity);
void			set_spot_direction(t_spot_light *spot, t_vec3 direction);
t_objs_list		*create_spotlight(t_spot_light *spotlight);

#endif