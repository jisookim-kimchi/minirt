/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   antialisign.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 19:18:25 by tfarkas           #+#    #+#             */
/*   Updated: 2025/07/25 13:22:12 by tfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_tools.h"


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

	The ray function can be used to get the ray from camera
	origin to the pixel point. After the pixel_center_color 
	function can be called if the return value changed to color_float.
	In this case in the image_hook function should be transform back to
	color_32 format.
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

t_ray	get_pixel_ray(int i, int j, uint32_t x, uint32_t y, t_camera *camera, int samples)
{
	t_ray	pixel_ray;
	t_vec3	u_horizontal;
	t_vec3	v_vertical;
	t_vec3	uv;

	u_horizontal = vec3_multiply(camera->delta_horizontal,
			(double)x + ((double)i + 0.5) / samples);
	v_vertical = vec3_multiply(camera->delta_vertical,
			(double)y + ((double)j + 0.5) / samples);
	uv = vec3_plus_vec3(u_horizontal, v_vertical);
	uv = vec3_plus_vec3(camera->left_bottom, uv);
	pixel_ray = ray(camera->transform_comp.pos, uv);
	return (pixel_ray);
}

t_color_float	n_samples_in_pixel(int samples, t_window *win,
	uint32_t x, uint32_t y)
{
	t_color_float	result;
	t_color_float	sample;
	t_ray			pixel_ray;
	int				i;
	int				j;

	i = 0;
	while (i < samples)
	{
		j = 0;
		while (j < samples)
		{
			pixel_ray = get_pixel_ray(i, j, x, y, &win->camera, samples);
			sample = pixel_sample_color(&pixel_ray, win);
			result = color_float_add(result, sample);
			j++;
		}
		i++;
	}
	result = color_float_divide(result, (double)samples);
	return (result);
}

/*
void	image_hook(void *param)
{
	t_window	*win;
	uint32_t	x;
	uint32_t	y;
	// uint32_t	blue;
	t_color_float temp;
	t_color_32	pixel_center_col;
	// t_ray		ray_pixel_center;
	int			samples;

	win = (t_window *)param;
	samples = 5;
	y = 0;
	while (y < win->image->height)
	{
		x = 0;
		while (x < win->image->width)
		{
			// get_ray_from_camera(&win->camera, &ray_pixel_center, x, y);
			// pixel_center_col = pixel_center_color(&ray_pixel_center, win);
			
			temp = n_samples_in_pixel(samples, win, x, y);
			pixel_center_col = color_transform_to_int(&temp);
			mlx_put_pixel(win->image, x, y, pixel_center_col.result_color);
			// mlx_put_pixel(win->image, x, y, blue);
			x++;
		}
		y++;
	}
}
*/

t_color_32	switch_antialisgn(t_window *win,
	uint32_t x, uint32_t y)
{
	t_color_32		pixel_center_col;
	t_ray			ray_pixel_center;
	t_color_float	temp;
	int				samples;

	samples = 5;
	ray_pixel_center = ray(vec3(0, 0, 0), vec3(1, 1, 1));
	if (win->antialisign_on == true)
	{
		temp = n_samples_in_pixel(samples, win, x, y);
		pixel_center_col = color_transform_to_int(&temp);
	}
	else
	{
		get_ray_from_camera(&win->camera, &ray_pixel_center, x, y);
		pixel_center_col = pixel_center_color(&ray_pixel_center, win);
	}
	return (pixel_center_col);
}
