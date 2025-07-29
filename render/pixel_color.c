/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 17:40:12 by tfarkas           #+#    #+#             */
/*   Updated: 2025/07/29 14:57:01 by jisokim2         ###   ########.fr       */
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

	// printf("%s\nIn the get_ray_from_camera function%s\n", MAGENTA, DEFAULT);
	// printf("The x: %i\ty: %i\n", x, y);
	// printf("The camera delta horizontal:\n");
	// print_vec3(&camera->delta_horizontal);
	// printf("The camera delta vertical:\n");
	// print_vec3(&camera->delta_vertical);
	ray->orign = camera->transform_comp.transform->position;
	u_horizontal = vec3_multiply(camera->delta_horizontal, (double)x);
	v_vertical = vec3_multiply(camera->delta_vertical, (double)y);
	uv = vec3_plus_vec3(u_horizontal, v_vertical);
	
	// sleep(1);
	// printf(CYAN);
	// printf("u_horizontal. x : %f, y : %f\n", u_horizontal.x, u_horizontal.y);
	// printf("v_vertical. x : %f, y : %f\n", v_vertical.x, v_vertical.y);
	// printf(DEFAULT);
	
	// printf("The uv vector:\n");
	// print_vec3(&uv);
	pixel_center = vec3_plus_vec3(camera->pixel00loc, uv);
	// printf("The pixel center\n");
	// print_vec3(&pixel_center);
	// printf("The ray origin\n");
	// print_vec3(&(ray->orign));
	ray->dir = vec3_normalized(vec3_sub_vec3(pixel_center, ray->orign));
}

/*
	The color_transform_to_int function change the color 
	float value  (which should be in the range 0.0 and 1.0)
	into uint_32 format which the renderer can use
*/

// void mlx_draw_pixel(uint8_t* pixel, uint32_t color)
// {
// 	*(pixel++) = (uint8_t)(color >> 24);
// 	*(pixel++) = (uint8_t)(color >> 16);
// 	*(pixel++) = (uint8_t)(color >> 8);
// 	*(pixel++) = (uint8_t)(color & 0xFF);
// }

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
	The shininess object related behavior. Now it is fixed value, but
	later can be added to the object material properties.

	The result hit color
	color = ambient + diff * light_color * object_color + spec * light_color;

	where ambient = ambient_ratio * ambient_color * object_color;
*/
t_color_float	calculate_hit_color(t_window *win, t_hit *hit)
{
	t_phong_terms	phong;
	t_color_float	result_float;

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

/*
	The pixel_center_color function return the color 
	value in uint32_t.
	If the ray hit an object, than return the hit structure hit colore value.
	Otherwise it return the background color
*/
t_color_32	pixel_center_color(t_ray *ray, t_window *win)
{
	t_color_32		result_color;
	t_color_float	temp;
	t_hit			record;

	set_ray_interval(&record, 0.001f, INFINITY);
	if (hit_world(ray, &record, win->objs))
	{
		// result_color.result_color = 0xFF0000FF;
		if (is_shadow(win->objs, &win->light, &record) == true)
			result_color = color_transform_to_int(&record.hit_color);
		else
		{
			temp = calculate_hit_color(win, &record);
			result_color = color_transform_to_int(&temp);
		}
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

