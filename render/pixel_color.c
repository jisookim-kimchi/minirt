/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 17:40:12 by tfarkas           #+#    #+#             */
/*   Updated: 2025/09/02 17:36:54 by tfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_tools.h"

/*
	Spot_light calculation part.
*/
// static void	spot_light_calculation(t_window *win, t_hit *hit,
// 	t_phong_terms *phong)
// {
// 	float			spot_intensity;
// 	float			spot_falloff;
// 	t_color_float	spot_color;

// 	if (is_in_spot_cone(&win->spot_light, hit->hit_point))
// 	{
// 		spot_intensity = spot_light_intensity_at(&win->spot_light,
// 				hit->hit_point);
// 		spot_falloff = spot_light_falloff(&win->spot_light, hit->hit_point);
// 		spot_color = color_float_multiply(win->spot_light.light_color,
// 				spot_intensity * spot_falloff);
// 		spot_color = color_float_multiply_vec3(spot_color, hit->hit_color);
// 		phong->diffuse_color = vec3_add(phong->diffuse_color,
// 				spot_color.red, spot_color.green, spot_color.blue);
// 	}
// }

/*
	The shininess object related behavior. Now it is fixed value, but
	later can be added to the object material properties.

	The result hit color
	color = ambient + diff * light_color * object_color + spec * light_color;

	where ambient = ambient_ratio * ambient_color * object_color;

	If the spot_light_calculation part will commented the spot_light
	effect won't display.
*/

// t_color_float	calculate_hit_color(t_window *win, t_hit *hit)
// {
// 	t_phong_terms	phong;
// 	t_color_float	result_float;

// 	if (hit->object.has_checkerboard)
// 		hit->hit_color = checkboard_pattern(hit);
// 	phong.diffuse_t = diffuse_term(hit, &win->light);
// 	phong.specular_t = specular_term(&win->camera, hit, &win->light, 12.0);
// 	phong.ambient_color = vec3_multiply(vec3_multiply_vec3(
// 				color_float_to_col3(win->ambient.ambient_color),
// 				color_float_to_col3(hit->hit_color)),
// 			win->ambient.ambient_ratio);
// 	phong.diffuse_color = vec3_multiply(vec3_multiply_vec3(
// 				color_float_to_col3(win->light.light_color),
// 				color_float_to_col3(hit->hit_color)),
// 			win->light.light_ratio * phong.diffuse_t);
// 	phong.specular_color = vec3_multiply(
// 			color_float_to_col3(win->light.light_color),
// 			win->light.light_ratio * phong.specular_t);
// 	spot_light_calculation(win, hit, &phong);
// 	phong.result = vec3_plus_vec3(phong.ambient_color,
// 			vec3_plus_vec3(phong.diffuse_color,
// 				phong.specular_color));
// 	result_float = color_col3_to_float(phong.result);
// 	return (result_float);
// }

/*
	calculate_hit_color function without spot_light
*/
t_color_float	calculate_hit_color(t_window *win, t_hit *hit)
{
	t_phong_terms	phong;
	t_color_float	result_float;

	if (hit->object.has_checkerboard)
		hit->hit_color = checkboard_pattern(hit);
	phong.diffuse_t = diffuse_term(hit, &win->light);
	phong.specular_t = specular_term(&win->camera, hit, &win->light, 12.0);
	phong.ambient_color = vec3_multiply(vec3_multiply_vec3(
				color_float_to_col3(win->ambient.ambient_color),
				color_float_to_col3(hit->hit_color)),
			win->ambient.ambient_ratio);
	phong.diffuse_color = vec3_multiply(vec3_multiply_vec3(
				color_float_to_col3(win->light.light_color),
				color_float_to_col3(hit->hit_color)),
			win->light.light_ratio * phong.diffuse_t);
	phong.specular_color = vec3_multiply(
			color_float_to_col3(win->light.light_color),
			win->light.light_ratio * phong.specular_t);
	phong.result = vec3_plus_vec3(phong.ambient_color,
			vec3_plus_vec3(phong.diffuse_color,
				phong.specular_color));
	result_float = color_col3_to_float(phong.result);
	return (result_float);
}

static void	pcc_object_hited(t_window *win, t_hit *record,
	t_color_32 *result_color, t_color_float	*temp)
{
	t_color_float	shadow_color;
	t_color_float	checker_color;

	record->object.has_checkerboard = win->objs->has_checkerboard;
	if (is_shadow(win->objs, &win->light, record) == true)
	{
		if (record->object.has_checkerboard)
		{
			checker_color = checkboard_pattern(record);
			shadow_color = color_float_multiply(checker_color,
					win->ambient.ambient_ratio);
			color_transform_to_int(&shadow_color, result_color);
		}
		else
		{
			shadow_color = color_float_multiply(record->hit_color,
					win->ambient.ambient_ratio);
			color_transform_to_int(&shadow_color, result_color);
		}
	}
	else
	{
		*temp = calculate_hit_color(win, record);
		color_transform_to_int(temp, result_color);
	}
}

/*
	pcc-object hitted function without checkboard pattern
*/
// static void	pcc_object_hited(t_window *win, t_hit *record,
// 	t_color_32 *result_color, t_color_float	*temp)
// {
// 	t_color_float	shadow_color;
// 	t_color_float	checker_color;

// 	if (is_shadow(win->objs, &win->light, record) == true)
// 	{
// 		if (record->object.has_checkerboard)
// 		{
// 			checker_color = checkboard_pattern(record);
// 			shadow_color = color_float_multiply(checker_color,
// 					win->ambient.ambient_ratio);
// 			color_transform_to_int(&shadow_color, result_color);
// 		}
// 		else
// 		{
// 			shadow_color = color_float_multiply(record->hit_color,
// 					win->ambient.ambient_ratio);
// 			color_transform_to_int(&shadow_color, result_color);
// 		}
// 	}
// 	else
// 	{
// 		*temp = calculate_hit_color(win, record);
// 		color_transform_to_int(temp, result_color);
// 	}
// }

/*
	The pixel_center_color function return the color 
	value in uint32_t.
	If the ray hit an object, than return the hit structure hit colore value.
	Otherwise it return the background color
*/
void	pixel_center_color(t_ray *ray, t_window *win, t_color_32 *result_color)
{
	t_color_float	temp;
	t_hit			record;

	if (!ray || !win || !win->objs || !result_color)
	{
		printf("Error : NULL PTR in pixel_center_color\n");
		clean_list_and_terminate(win);
	}
	set_ray_interval(&record, 0.001f, INFINITY);
	if (hit_world(ray, &record, win->objs))
		pcc_object_hited(win, &record, result_color, &temp);
	else
	{
		temp = color_float_multiply(win->ambient.ambient_color,
				win->ambient.ambient_ratio);
		color_transform_to_int(&temp, result_color);
	}
}
