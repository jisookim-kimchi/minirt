/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 20:54:35 by tfarkas           #+#    #+#             */
/*   Updated: 2025/07/21 18:45:59 by tfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lighting.h"

t_light	init_light(t_vec3 in_pos, float in_bright_ratio,
	t_color_float in_color)
{
	t_light	l;

	l.light_position = in_pos;
	if (check_value_in_range(in_bright_ratio, 0.0f, 1.0f) == false)
	{
		printf("%sThe light's brightness ratio %f is not"
			" fit in the interval. The value modified"
			" to the limit value to be able to run the"
			" program.%s\n", RED, in_bright_ratio, DEFAULT);
		in_bright_ratio = clamp_calculation(in_bright_ratio, 0.0f, 1.0f);
	}
	l.light_ratio = in_bright_ratio;
	l.light_color = in_color;
	return (l);
}

t_ambient	init_ambient(float in_ambient_ratio, t_color_float in_color)
{
	t_ambient	amb;

	if (check_value_in_range(in_ambient_ratio, 0.0f, 1.0f) == false)
	{
		printf("%sThe ambient light ratio %f is not"
			" fit in the interval. The value modified"
			" to the limit value to be able to run the"
			" program.%s\n", RED, in_ambient_ratio, DEFAULT);
		in_ambient_ratio = clamp_calculation(in_ambient_ratio, 0.0f, 1.0f);
	}
	amb.ambient_ratio = in_ambient_ratio;
	amb.ambient_color = in_color;
	return (amb);
}

/*
	norm_light_dir = normalized(light position - hit_point)
*/
double	diffuse_term(t_hit *hit, t_light *light)
{
	double	diffuse_t;
	t_vec3	norm_light_dir;

	norm_light_dir = vec3_normalized(vec3_sub_vec3(light->light_position,
				hit->hit_point));
	diffuse_t = vec3_dot(hit->normal, norm_light_dir);
	//clamp_calculation() with double!!!!!
	return (diffuse_t);
}
