/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   antialisign.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 19:18:25 by tfarkas           #+#    #+#             */
/*   Updated: 2025/07/23 21:01:23 by tfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "antialisign.h"


/*
void	 get_ray_from_camera(t_camera *camera, t_ray *ray,
	uint32_t x, uint32_t y)
{
	t_vec3	pixel_center;
	t_vec3	u_horizontal;
	t_vec3	v_vertical;
	t_vec3	uv;

	ray->orign = camera->transform_comp.pos;
	u_horizontal = vec3_multiply(camera->delta_horizontal, (double)x);
	v_vertical = vec3_multiply(camera->delta_vertical, (double)y);
	uv = vec3_plus_vec3(u_horizontal, v_vertical);
	pixel_center = vec3_plus_vec3(camera->pixel00loc, uv);
	ray->dir = vec3_normalized(vec3_sub_vec3(pixel_center, ray->orign));
}


t_color_32	pixel_center_color(t_ray *ray, t_window *win)
{
	t_color_32		result_color;
	t_color_float	temp;
	t_hit			record;

	set_ray_interval(&record, 0.001f, INFINITY);
	if (hit_world(ray, &record, win->objs))
	{
		// result_color.result_color = 0xFF0000FF;
		temp = calculate_hit_color(win, &record);
		result_color = color_transform_to_int(&temp);
	}
	else
	{
		// result_color.result_color = 0xFF000000;
		temp = color_float_multiply(win->ambient.ambient_color,
				win->ambient.ambient_ratio);
		result_color = color_transform_to_int(&temp);
	}
	return (result_color);
}
*/


t_color_float	n_samples_in_pixel(int samples)
{
	t_color_float	result;
	int				i;
	int				j;

	i = 0;
	while (i < samples)
	{
		j = 0;
		while (j < samples)
		{
			
			j++;
		}
		i++;
	}
	result = color_float_divide(result, (double)samples);
	return (result);
}