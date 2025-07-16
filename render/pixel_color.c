/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 17:40:12 by tfarkas           #+#    #+#             */
/*   Updated: 2025/07/16 14:48:23 by tfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../Precompiled/loadresource.h"
//#include "../object/objects.h"
#include "../mlx_tools.h"
/*
	The get_ray_from_camera function calculate the ray direction for the viewport
	pixel center.
	u_horizontal = the x double value multiply by the delta_horizontal vector
	v_horizontal = the y double value multiply by the delta_vertical vector
	uv = u_horizontal + v_horizontal
	pixel_center = pixel00loc + uv
	ray->dir = pixel_center - ray->orig

	TODO:
	Check if camera->transform_comp.pos is ok. Maybe it need to change
	camera->transform_comp->pos. It is depend on the structure scope
*/

void	get_ray_from_camera(t_camera *camera, t_ray *ray,
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
	printf("The pixel center\n");
	print_vec3(&pixel_center);
	printf("The ray origin\n");
	print_vec3(&(ray->orign));
	ray->dir = vec3_normalized(vec3_sub_vec3(pixel_center, ray->orign));
}

/*
	The color_transform_to_int function change the color 
	float value  (which should be in the range 0.0 and 1.0)
	into uint_32 format which the renderer can use
*/
t_color_32	color_transform_to_int(t_color_float *col_float)
{
	t_color_32	col_32;

	col_32.red = (uint32_t)(255.999
			* clamp_calculation(col_float->red, 0.0f, 1.0f));
	col_32.green = (uint32_t)(255.999
			* clamp_calculation(col_float->green, 0.0f, 1.0f));
	col_32.blue = (uint32_t)(255.999
			* clamp_calculation(col_float->blue, 0.0f, 1.0f));
	col_32.alpha = 255;
	col_32.result_color = (col_32.red << 24) | (col_32.green << 16)
		| (col_32.blue << 8) | (col_32.alpha);
	return (col_32);
}

/*
	The pixel_center_color function return the color 
	value in uint32_t.
	If the ray hit an object, than return the hit structure hit colore value.
	Otherwise it return the background color
*/
t_color_32	pixel_center_color(t_ray *ray, t_window *win)
{
	t_color_32	result_color;
	t_hit		record;

	set_ray_interval(&record, 0.001f, INFINITY);
	if (hit_world(ray, &record, win->objs))
	{
		result_color = color_transform_to_int(&record.hit_color);
	}
	else
	{
		result_color = color_transform_to_int(&win->ambient);
	}
	return (result_color);
}

