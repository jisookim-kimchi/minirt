/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 17:40:12 by tfarkas           #+#    #+#             */
/*   Updated: 2025/08/28 18:33:16 by tfarkas          ###   ########.fr       */
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

	//memo make offset of ray from camera 
	ray->orign = vec3_plus_vec3(camera->transform_comp.transform.position,
                            vec3_multiply(camera->transform_comp.forward, EPSILON));
	//ray->orign = camera->transform_comp.transform->position;
	u_horizontal = vec3_multiply(camera->delta_horizontal, (double)x);
	v_vertical = vec3_multiply(camera->delta_vertical, (double)y);
	uv = vec3_plus_vec3(u_horizontal, v_vertical);
	pixel_center = vec3_plus_vec3(camera->pixel00loc, uv);
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

void	color_transform_to_int(t_color_float *col_float, t_color_32 *col_32)
{
	if (!col_float || !col_32)
	{
		printf("Error: Null pointer in color_transform_to_int\n");
		return;
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
//TODO look at it !
t_color_float checkboard_pattern(t_hit *hit, t_color_float white, t_color_float black)
{
	float u_scaled = 0.0;
	float v_scaled = 0.0;
	if(hit->object.obj_type == SPHERE)
	{
		t_sphere *sphere = (t_sphere*)hit->object.data;
		u_scaled = sphere->uv.u * sphere->uv.tile_scale;
		v_scaled = sphere->uv.v * sphere->uv.tile_scale;
	}
	if(hit->object.obj_type == PLANE)
	{
		t_plane *plane = (t_plane *)hit->object.data;
        u_scaled = plane->uv.u * plane->uv.tile_scale;
        v_scaled = plane->uv.v * plane->uv.tile_scale;
	}
	if(hit->object.obj_type == CYLINDER)
	{
		t_cylinder *cylinder = (t_cylinder *)hit->object.data;
		if (cylinder->is_topcap_hit || cylinder->is_bottomcap_hit)
        {
            u_scaled = cylinder->cap_uv.u * cylinder->cap_uv.tile_scale;
            v_scaled = cylinder->cap_uv.v * cylinder->cap_uv.tile_scale;
        }
        else if (cylinder->is_side_hit)
        {
            u_scaled = cylinder->side_uv.u * cylinder->side_uv.tile_scale;
            v_scaled = cylinder->side_uv.v * cylinder->side_uv.tile_scale;
        }
	}
    int u_int = (int)floor(u_scaled);
    int v_int = (int)floor(v_scaled);
	if ((u_int + v_int) % 2 == 0)
   		return white;
	else
    	return black;
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
	
	if (hit->object.has_checkerboard)
	{
		t_color_float white = {1.0, 1.0, 1.0};
		t_color_float black = {0.0, 0.0, 0.0};
		hit->hit_color = checkboard_pattern(hit, white, black);
	}
	
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

	//FOR SPOT_LIGHT
	// if (is_in_spot_cone(&win->spot_light, hit->hit_point))
	// {
    // 	float spot_intensity = spot_light_intensity_at(&win->spot_light, hit->hit_point);
    // 	float spot_falloff = spot_light_falloff(&win->spot_light, hit->hit_point);
		
    // 	t_color_float spot_color = color_float_multiply(win->spot_light.light.light_color, spot_intensity * spot_falloff);
    // 	spot_color = color_float_multiply_vec3(spot_color, hit->hit_color);
    // 	phong.diffuse_color = vec3_add(phong.diffuse_color, spot_color.red, spot_color.green, spot_color.blue);
	// }
	
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
void	pixel_center_color(t_ray *ray, t_window *win, t_color_32 *result_color)
{
	t_color_float	temp;
	t_hit			record;
	t_color_float	shadow_color;
	
	if (!ray || !win || !win->objs || !result_color)
	{
		printf("Error : NULL PTR in pixel_center_color\n");
		exit(1);
	}
	set_ray_interval(&record, 0.001f, INFINITY);
	if (hit_world(ray, &record, win->objs))
	{
		if (record.object.obj_type == SPHERE)
		{
			record.object.has_checkerboard = true;
			win->objs->has_checkerboard = true;
		}
		else if (record.object.obj_type == PLANE)
		{
			record.object.has_checkerboard = true;
			win->objs->has_checkerboard = true;
		}
		else if (record.object.obj_type == CYLINDER)
		{
			record.object.has_checkerboard = true;
			win->objs->has_checkerboard = true;
		}
		else
		{
			record.object.has_checkerboard = false;	
			win->objs->has_checkerboard = false;
		}
		if (is_shadow(win->objs, &win->light, &record) == true)
		{
			// t_cylinder *c = (t_cylinder*)win->objs->data;
			// if (c)
			// {
			// 	t_color_float white = {1.0, 1.0, 1.0};
			// 	t_color_float black = {0.0, 0.0, 0.0};
			// 	t_color_float checker_color = checkboard_pattern(&record, white, black);
			// 	shadow_color = color_float_multiply(checker_color, win->ambient.ambient_ratio);
			// 	color_transform_to_int(&shadow_color, result_color);
			// 	printf("cylinder shadow_color %f %f %f\n", shadow_color.red, shadow_color.green, shadow_color.blue);
			// }
			// t_sphere *s = (t_sphere *)win->objs->data;
			// if (s)
			// {
			// 	t_color_float white = {1.0, 1.0, 1.0};
			// 	t_color_float black = {0.0, 0.0, 0.0};
			// 	t_color_float checker_color = checkboard_pattern(&record, white, black);
			// 	shadow_color = color_float_multiply(checker_color, win->ambient.ambient_ratio);
			// 	color_transform_to_int(&shadow_color, result_color);
			// 	printf("sphere shadow_color %f %f %f\n", shadow_color.red, shadow_color.green, shadow_color.blue);
			// }
			if (record.object.has_checkerboard)
			{
				t_color_float white = {1.0, 1.0, 1.0};
				t_color_float black = {0.0, 0.0, 0.0};
				t_color_float checker_color = checkboard_pattern(&record, white, black);
				shadow_color = color_float_multiply(checker_color, win->ambient.ambient_ratio);
				color_transform_to_int(&shadow_color, result_color);
			}
			else
			{
				shadow_color = color_float_multiply(record.hit_color, win->ambient.ambient_ratio);
				color_transform_to_int(&shadow_color, result_color);
			}

			// shadow_color = color_float_multiply(record.hit_color, win->ambient.ambient_ratio);
			// color_transform_to_int(&shadow_color, result_color);
		}
		else
		{
			//printf("else record type %d\n", record.object.obj_type);
			temp = calculate_hit_color(win, &record);
			color_transform_to_int(&temp, result_color);
		}
	}
	else
	{
		//result_color.result_color = 0xFF000000;
		temp = color_float_multiply(win->ambient.ambient_color,
				win->ambient.ambient_ratio);
		color_transform_to_int(&temp, result_color);
	}
}

