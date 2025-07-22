/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 20:54:35 by tfarkas           #+#    #+#             */
/*   Updated: 2025/07/22 17:57:04 by jisokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lighting.h"
#include "../mlx_tools.h"

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
	light_reflect function calculates the reflection of the light
	angle = dot(light_dir, normal)

	(important the light_dir in this case point towards to the hit point)
*/
t_vec3	light_reflect(t_vec3 light_dir, t_vec3 normal)
{
	t_vec3	reflect;
	double	angle;

	angle = vec3_dot(light_dir, normal);
	reflect = vec3_sub_vec3(light_dir, vec3_multiply(normal, 2 * angle));
	return (reflect);
}

/*
	norm_light_dir = normalized(light position - hit_point)
	diffuse_t = dot product(hit_normal, norm_light_dir)
	
	The diffuse_t shouldn't be negative value! This reason 
	the double_clamp_calculation used. It set the minimum value 0,
	if the diffuse_t less than 0. 
*/
double	diffuse_term(t_hit *hit, t_light *light)
{
	double	diffuse_t;
	t_vec3	norm_light_dir;

	norm_light_dir = vec3_normalized(vec3_sub_vec3(light->light_position,
				hit->hit_point));
	diffuse_t = vec3_dot(hit->normal, norm_light_dir);
	double_clamp_calculation(diffuse_t, 0.0, INFINITY);
	return (diffuse_t);
}

/*
	specular term - shiny highlights from smooth surfaces

	shininess - Controls how focused or spread out the highlight
	norm_light_dir = normalized(hit_point - light position)
	norm_camera_dir = normalized(camera position - hit_point)
	specular_t = pow(max(dot(relflect, norm_camera_dir), 0.0), shininess)

	In the function the specular_t value calculated 3 steps, not in one big line
*/
double	specular_term(t_camera *camera, t_hit *hit,
		t_light *light, double shininess)
{
	double	specular_t;
	t_vec3	norm_light_dir;
	t_vec3	norm_camera_dir;
	t_vec3	reflect;

	norm_light_dir = vec3_normalized(vec3_sub_vec3(hit->hit_point,
				light->light_position));
	norm_camera_dir = vec3_normalized(vec3_sub_vec3(camera->transform_comp.pos,
				hit->hit_point));
	reflect = light_reflect(norm_light_dir, hit->normal);
	specular_t = vec3_dot(reflect, norm_camera_dir);
	specular_t = double_clamp_calculation(specular_t, 0.0, INFINITY);
	specular_t = pow(specular_t, shininess);
	return (specular_t);
}

/*
	The shininess object related behavior. Now it is fixed value, but
	later can be added to the object material properties.

	The result hit color
	color = ambient + diff * light_color * object_color + spec * light_color;

	where ambient = ambient_ratio * ambient_color * object_color;
*/

// t_color_float	hit_color(t_window *win, t_hit *hit)
// {
// 	t_phong_terms	phong;

// 	phong.diffuse_t = diffuse_term(hit, &win->light);
// 	phong.specular_t = specular_term(&win->camera, hit, &win->light, 32.0);
// 	phong.result = phong.ambient_color + phong.diffuse_color + phong.specular_color;
// }
