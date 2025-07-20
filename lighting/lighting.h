/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 20:36:12 by tfarkas           #+#    #+#             */
/*   Updated: 2025/07/20 21:46:04 by tfarkas          ###   ########.fr       */
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
}	t_light;

typedef struct s_ambient
{
	float			ambient_ratio;
	t_color_float	ambient_color;
}	t_ambient;

t_light		init_light(t_vec3 in_pos, float in_bright_ratio,
				t_color_float in_color);
t_ambient	init_ambient(float in_ambient_ratio, t_color_float in_color);

#endif