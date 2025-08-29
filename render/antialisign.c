/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   antialisign.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 19:18:25 by tfarkas           #+#    #+#             */
/*   Updated: 2025/08/29 17:21:49 by tfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_tools.h"

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

	set_ray_interval(&record, 0.001f, INFINITY);
	if (hit_world(ray, &record, win->objs))
	{
		temp = calculate_hit_color(win, &record);
	}
	else
	{
		temp = color_float_multiply(win->ambient.ambient_color,
				win->ambient.ambient_ratio);
	}
	return (temp);
}

t_ray	get_pixel_ray(t_window *win)
{
	t_ray	pixel_ray;
	t_vec3	u_horizontal;
	t_vec3	v_vertical;
	t_vec3	uv;
	t_vec3	ray_dir;

	u_horizontal = vec3_multiply(win->camera.delta_horizontal,
			(double)(win->antialisign.x) + ((double)(win->antialisign.i + 0.5))
			/ win->antialisign.samples_num);
	v_vertical = vec3_multiply(win->camera.delta_vertical,
			(double)win->antialisign.y + ((double)win->antialisign.j + 0.5)
			/ win->antialisign.samples_num);
	uv = vec3_plus_vec3(u_horizontal, v_vertical);
	uv = vec3_plus_vec3(win->camera.left_bottom, uv);
	ray_dir = vec3_sub_vec3(uv, win->camera.left_bottom);
	pixel_ray = create_ray(win->camera.transform_comp.transform.position, uv);
	return (pixel_ray);
}

/*
	In the n_sample_in_pixel function the pixel_sample_color should replaced with
	pixel_center_color. However the pixel_center_color need to modify it
	can store the result in t_color_float datatype too.
*/
t_color_float	n_samples_in_pixel(t_window *win)
{
	t_color_float	result;
	t_color_float	sample;
	t_ray			pixel_ray;

	win->antialisign.i = 0;
	color_float_set(&result, 0.0f, 0.0f, 0.0f);
	while (win->antialisign.i < win->antialisign.samples_num)
	{
		win->antialisign.j = 0;
		while (win->antialisign.j < win->antialisign.samples_num)
		{
			pixel_ray = get_pixel_ray(win);
			sample = pixel_sample_color(&pixel_ray, win);
			result = color_float_add(result, sample);
			win->antialisign.j++;
		}
		win->antialisign.i++;
	}
	result = color_float_divide(result,
			(double)(win->antialisign.samples_num
				* win->antialisign.samples_num));
	return (result);
}

void	switch_antialisgn(t_window *win,
	t_color_32 *pixel_center_col)
{
	t_ray			ray_pixel_center;
	t_color_float	temp;

	win->antialisign.samples_num = 5;
	ray_pixel_center = create_ray(vec3(0, 0, 0), vec3(1, 1, 1));
	if (win->antialisign.antialisign_on == true)
	{
		temp = n_samples_in_pixel(win);
		color_transform_to_int(&temp, pixel_center_col);
	}
	else
	{
		get_ray_from_camera(win, &ray_pixel_center);
		pixel_center_color(&ray_pixel_center, win, pixel_center_col);
	}
}
