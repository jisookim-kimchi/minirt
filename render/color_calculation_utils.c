/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_calculation_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 11:44:54 by tfarkas           #+#    #+#             */
/*   Updated: 2025/08/30 11:47:05 by tfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	get_ray_from_camera(t_window *win, t_ray *ray)
{
	t_vec3	pixel_center;
	t_vec3	u_horizontal;
	t_vec3	v_vertical;
	t_vec3	uv;

	ray->orign = vec3_plus_vec3(win->camera.transform_comp.transform.position,
			vec3_multiply(win->camera.transform_comp.forward, EPSILON));
	u_horizontal = vec3_multiply(win->camera.delta_horizontal,
			(double)(win->antialisign.x));
	v_vertical = vec3_multiply(win->camera.delta_vertical,
			(double)(win->antialisign.y));
	uv = vec3_plus_vec3(u_horizontal, v_vertical);
	pixel_center = vec3_plus_vec3(win->camera.pixel00loc, uv);
	ray->dir = vec3_normalized(vec3_sub_vec3(pixel_center, ray->orign));
}

/*
	The color_transform_to_int function change the color 
	float value  (which should be in the range 0.0 and 1.0)
	into uint_32 format which the renderer can use
*/

void	color_transform_to_int(t_color_float *col_float, t_color_32 *col_32)
{
	if (!col_float || !col_32)
	{
		printf("Error: Null pointer in color_transform_to_int\n");
		return ;
	}
	col_32->red = (uint32_t)(255.999
			* clamp_calculation(col_float->red, 0.0f, 1.0f));
	col_32->green = (uint32_t)(255.999
			* clamp_calculation(col_float->green, 0.0f, 1.0f));
	col_32->blue = (uint32_t)(255.999
			* clamp_calculation(col_float->blue, 0.0f, 1.0f));
	col_32->alpha = 255;
	col_32->result_color = (col_32->red << 24) | (col_32->green << 16)
		| (col_32->blue << 8) | (col_32->alpha);
}
