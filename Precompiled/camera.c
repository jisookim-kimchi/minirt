/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 15:19:39 by jisokim2          #+#    #+#             */
/*   Updated: 2025/08/30 15:28:31 by jisokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loadresource.h"

/*
	Get camera orientation
	camera->horizontal : horizontal vector.
	camera->vertical : vertical vector.
	camera->delta_horizontal or vertical =
	The 3D directional vector change when moving one pixel to the right or down .
*/
static void	camera_orientation(t_camera *camera)
{
	t_vec3	right;
	t_vec3	up;

	right = get_right_vector(camera->transform_comp);
	up = get_up_vector(camera->transform_comp);
	camera->horizontal = vec3_multiply(right, camera->viewport_w);
	camera->vertical = vec3_multiply(up, -camera->viewport_h);
	camera->delta_horizontal = vec3_divide(camera->horizontal,
			(double)IMAGE_WIDTH);
	camera->delta_vertical = vec3_divide(camera->vertical,
			(double)IMAGE_HEIGHT);
}

/*
	The calculate_pixel00loc is a helper function to execute
	the pixel00loc value. This does the following steps:
	sum_delta_hv = add delta_horizontal vector to the delta_vertical vector
	half_sum_delta_hv = sum_delta_hv divided by 2
	camera->pixel00loc = add camera->left_bottom vector to
						half_sum_delta_hv vector
*/
static void	calculate_pixel00loc(t_camera *camera)
{
	t_vec3	sum_delta_hv;
	t_vec3	half_sum_delta_hv;

	sum_delta_hv = vec3_plus_vec3(camera->delta_horizontal,
			camera->delta_vertical);
	half_sum_delta_hv = vec3_divide(sum_delta_hv, 2.0);
	camera->pixel00loc = vec3_plus_vec3(camera->left_bottom,
			half_sum_delta_hv);
}

/*
	We need to consider how we want to pass the information
	about mlx image_width and image_height size. Currently
	it use the mlx_tools.h IMAGE_WIDTH and IMAGE_RATIO values
*/
t_camera	init_camera(t_screenpoint screen, t_transform_comp transform_comp)
{
	t_camera	camera;
	float		theta;
	float		half_of_fov;
	t_vec3		camera_position;
	t_vec3		center;

	camera.transform_comp = transform_comp;
	camera.fov = 60.f;
	theta = deg2rad(camera.fov);
	half_of_fov = theta / 2.f;
	camera.focal_length = 1 / tanf(half_of_fov);
	camera.viewport_h = 2.f * tanf(half_of_fov);
	camera.viewport_w = camera.viewport_h * screen.aspect_ratio;
	camera_position = get_world_position(&camera.transform_comp);
	camera_orientation(&camera);
	camera.transform_comp.forward = (t_vec3){0, 0, -1};
	center = vec3_plus_vec3(camera_position,
			vec3_multiply(camera.transform_comp.forward, camera.focal_length));
	camera.left_bottom = vec3_sub_vec3(center,
			vec3_multiply(camera.horizontal, 0.5));
	camera.left_bottom = vec3_sub_vec3(camera.left_bottom,
			vec3_multiply(camera.vertical, 0.5));
	calculate_pixel00loc(&camera);
	return (camera);
}

struct s_transform_comp	get_transform_comp(t_camera *camera)
{
	return (camera->transform_comp);
}

// float get_fov(const t_camera *camera)
// {
// 	return camera->fov;
// }

// void	setfov(float infov, t_camera *camera)
// {
// 	camera->fov = infov;
// }
/*
	change modeling matrix to view matrix
	modeling matrix ?? : local - >world
	view matrix : world -> camera
*/
// void    get_view_axes(t_vec3 *outview_x, 
//	const t_vec3 *outview_y, const t_vec3 *outview_z)
// {
//     outview_x = -getlocal_x()
//     outview_y = getlocal_y()
//     outview_z = -getlocal_z();
// }

/*
	get view axes
*/
// t_matrix_4x4    get_view_matrix(t_transform_comp * transform)
// {
//     t_vec3  view_x;
//     t_vec3  view_y;
//     t_vec3  view_z;

//     get_view_axes(view_x, view_y, view_z);
//     t_vec3  pos = get_world_position(transform);

//     return t_matrix_4x4
//     (
//         t_vec4(t_vec3(),)
//         t_vec4(t_vec3(),)
//         t_vec4(t_vec3(),)
//         t_vec4(view_x)
//     )
// }

// void    set_look_at_rotation_vec3(t_camera *camera,
//	const t_vec3 in_target_position, const t_vec3 in_up)
// {
//     t_vec3  local_x;
//     t_vec3  local_y;
//     t_vec3  local_z;

//     local_z = vec3_sub_vec3(in_target_position,
//			camera->transform_comp.world_transform->position);
//     local_z = vec3_normalized(local_z);

//     if(fabs(local_z.y) >= (1.f - 1e-8))
//     {
//         local_x = vec3(1.f, 0.f, 0.f);
//     }
//     else
//     {
//         local_x = vec3_cross(in_up, local_z);
//         local_x = vec3_normalized(local_x);
//     }
//     local_y = vec3_cross(local_z, local_x);

//     camera->transform_comp.up = local_y;
//     camera->transform_comp.right = local_x;
//     camera->transform_comp.forward = local_z;
// }

// float   get_far_clip(const t_camera *camera)
// {
//     return camera->far_clip;
// }

// float   get_near_clip(const t_camera *camera)
// {
//     return camera->near_clip;
// }

// void    set_near_clip(t_camera *camera, float in_near_clip)
// {
//     camera->near_clip = in_near_clip;
// }

// void    set_far_clip(t_camera *camera, float in_far_clip)
// {
//     camera->far_clip = in_far_clip;
// }
