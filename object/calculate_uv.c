/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_uv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 16:35:23 by jisokim2          #+#    #+#             */
/*   Updated: 2025/08/29 17:15:27 by jisokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

void	calculate_sphere_uv(t_sphere *sphere, t_vec3 hit_point)
{
	t_vec3	temp;
	t_vec3	temp_n;
	double	temp_cos_theta;
	double	theta;
	double	phi;

	temp = vec3_sub_vec3(hit_point, sphere->center);
	temp_n = vec3_normalized(temp);
	temp_cos_theta = vec3_dot(temp_n, (t_vec3){0, 1, 0});
	theta = acos(temp_cos_theta);
	phi = atan2(temp_n.z, temp_n.x);
	sphere->uv.u = (phi + M_PI) / (2 * M_PI);
	sphere->uv.v = theta / M_PI;
	sphere->uv.tile_scale = sphere->diameter / (sphere->diameter / 10);
}

void	calculate_plane_uv(t_plane *plane, t_vec3 hit_point)
{
	t_vec3	up;
	t_vec3	u;
	t_vec3	v;
	t_vec3	hit_to_origin;

	up = (t_vec3){0, 1, 0};
	if (fabs(plane->unit_normal_vec.x) > fabs(plane->unit_normal_vec.y)
		&& fabs(plane->unit_normal_vec.x) > fabs(plane->unit_normal_vec.z))
		up = (t_vec3){0, 1, 0};
	else if (fabs(plane->unit_normal_vec.y) > fabs(plane->unit_normal_vec.z))
		up = (t_vec3){0, 0, 1};
	else
		up = (t_vec3){1, 0, 0};
	u = vec3_normalized(vec3_cross(up, plane->unit_normal_vec));
	v = vec3_normalized(vec3_cross(plane->unit_normal_vec, u));
	hit_to_origin = vec3_sub_vec3(hit_point, plane->point);
	plane->uv.u = vec3_dot(hit_to_origin, u);
	plane->uv.v = vec3_dot(hit_to_origin, v);
	plane->uv.tile_scale = 0.01;
}

void	uv_calculate_clyinder_side(t_cylinder *cylinder, t_vec3 hit_point)
{
	double	phi;
	double	height_projection;
	t_vec3	axis_to_hit;
	t_vec3	hit_point_flat;

	axis_to_hit = vec3_sub_vec3(hit_point, cylinder->center);
	height_projection = vec3_dot(axis_to_hit, cylinder->axis);
	hit_point_flat = vec3_sub_vec3(axis_to_hit,
			vec3_multiply(cylinder->axis, height_projection));
	if (fabs(cylinder->axis.x) > fabs(cylinder->axis.y)
		&& fabs(cylinder->axis.x) > fabs(cylinder->axis.z))
		phi = atan2(hit_point_flat.z, hit_point_flat.y);
	else if (fabs(cylinder->axis.y) > fabs(cylinder->axis.x)
		&& fabs(cylinder->axis.y) > fabs(cylinder->axis.z))
		phi = atan2(hit_point_flat.z, hit_point_flat.x);
	else
		phi = atan2(hit_point_flat.y, hit_point_flat.x);
	cylinder->side_uv.u = (phi + M_PI) / (2 * M_PI);
	cylinder->side_uv.v = (height_projection + cylinder->height / 2)
		/ cylinder->height;
	cylinder->side_uv.tile_scale = 10;
}

void	uv_calculate_cylinder_cap(t_cylinder *cyl, t_vec3 cap_center,
	t_vec3 cap_normal, t_vec3 hit_point)
{
	t_vec3	center_to_hit;
	t_vec3	u_dir;
	t_vec3	v_dir;
	double	u_local;
	double	v_local;
	double	cap_radius;

	center_to_hit = vec3_sub_vec3(hit_point, cap_center);
	if (fabs(cap_normal.x) > fabs(cap_normal.y)
		&& fabs(cap_normal.x) > fabs(cap_normal.z))
		u_dir = (t_vec3){0, 1, 0};
	else if (fabs(cap_normal.y) > fabs(cap_normal.z))
		u_dir = (t_vec3){0, 0, 1};
	else
		u_dir = (t_vec3){1, 0, 0};
	v_dir = vec3_cross(cap_normal, u_dir);
	u_local = vec3_dot(center_to_hit, u_dir);
	v_local = vec3_dot(center_to_hit, v_dir);
	cap_radius = cyl->diameter * 0.5;
	cyl->cap_uv.u = 0.5 + (u_local / cap_radius) * 0.5;
	cyl->cap_uv.v = 0.5 + (v_local / cap_radius) * 0.5;
	cyl->cap_uv.tile_scale = 10;
}
