/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   antialisign_shadow.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 07:14:16 by tfarkas           #+#    #+#             */
/*   Updated: 2025/09/02 17:36:06 by tfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_tools.h"

static t_color_float	antialisign_pcc_object_hited(t_window *win,
	t_hit *record, t_color_float *temp)
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
			return (shadow_color);
		}
		else
		{
			shadow_color = color_float_multiply(record->hit_color,
					win->ambient.ambient_ratio);
			return (shadow_color);
		}
	}
	else
		*temp = calculate_hit_color(win, record);
	return (*temp);
}

/*
	Without checkboard pattern
*/
// static t_color_float	antialisign_pcc_object_hited(t_window *win,
// 	t_hit *record, t_color_float *temp)
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
// 			return (shadow_color);
// 		}
// 		else
// 		{
// 			shadow_color = color_float_multiply(record->hit_color,
// 					win->ambient.ambient_ratio);
// 			return (shadow_color);
// 		}
// 	}
// 	else
// 		*temp = calculate_hit_color(win, record);
// 	return (*temp);
// }

/*
	The ray function can be used to get the ray from camera
	origin to the pixel point. After the pixel_center_color 
	function can be called if the return value changed to color_float.
	In this case in the image_hook function should be transform back to
	color_32 format.

	The pixel_smaple_color function use that logic, which does not
	include the shadow and checkerboard part. Later in the n_samples_in_pixel
	function the pixel_sample_color should change to pixel_center_color 
*/
t_color_float	pixel_sample_color(t_ray *ray, t_window *win)
{
	t_color_float	temp;
	t_hit			record;

	if (!ray || !win || !win->objs)
	{
		printf("Error : NULL PTR in pixel_center_color\n");
		clean_list_and_terminate(win);
	}
	set_ray_interval(&record, 0.001f, INFINITY);
	if (hit_world(ray, &record, win->objs))
	{
		temp = antialisign_pcc_object_hited(win, &record, &temp);
	}
	else
	{
		temp = color_float_multiply(win->ambient.ambient_color,
				win->ambient.ambient_ratio);
	}
	return (temp);
}
