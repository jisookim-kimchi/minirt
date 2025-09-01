/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder_cap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 13:49:08 by jisokim2          #+#    #+#             */
/*   Updated: 2025/09/01 16:39:26 by tfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

static bool	hit_cylinder_cap(t_cylinder *cylinder,
	t_cap *cap, t_ray *ray, t_hit *hit)
{
	double		radius;
	double		check;
	double		t;
	t_point3	hit_point;

	t = 0.0;
	radius = cylinder->diameter / 2;
	check = vec3_dot(ray->dir, cap->normal);
	if (fabs(check) < EPSILON)
		return (false);
	t = vec3_dot(vec3_sub_vec3(cap->center, ray->orign), cap->normal) / check;
	if (t < hit->t_min || t > hit->t_max)
		return (false);
	hit_point = ray_at(ray, t);
	if (vec3_length_squared(vec3_sub_vec3(hit_point,
				cap->center)) > radius * radius)
		return (false);
	hit->t = t;
	hit->hit_point = hit_point;
	hit->hit_color = cylinder->cylinder_color;
	set_ray_opposite_normal(ray, hit, cap->normal);
	uv_calculate_cylinder_cap(cylinder, cap->center,
		cap->normal, hit->hit_point);
	return (true);
}

static void	cal_caps(t_cylinder *cylinder, t_cap *top_cap, t_cap *bottom_cap)
{
	double	half_height;
	t_vec3	up;
	t_vec3	down;

	half_height = cylinder->height / 2.f;
	up = vec3_normalized(cylinder->axis);
	down = vec3_multiply(up, -1.0);
	top_cap->center = vec3_plus_vec3(cylinder->center,
			vec3_multiply(up, half_height));
	top_cap->normal = up;
	bottom_cap->center = vec3_plus_vec3(cylinder->center,
			vec3_multiply(down, half_height));
	bottom_cap->normal = down;
}

bool	hit_cylinder(t_cylinder *cylinder, t_ray *ray, t_hit *hit, bool shadow_part)
{
	t_cap	top_cap;
	t_cap	bottom_cap;
	bool	is_hit;

	is_hit = false;
	if (!cylinder || !ray || !hit)
		return (false);
	cal_caps(cylinder, &top_cap, &bottom_cap);
	is_hit = hit_cylinder_side(cylinder, ray, hit)
		|| hit_cylinder_cap(cylinder, &top_cap, ray, hit)
		|| hit_cylinder_cap(cylinder, &bottom_cap, ray, hit);
	if (is_hit)
	{
		hit->object.obj_type = CYLINDER;
		hit->object.data = cylinder;
		hit->hit_color = cylinder->cylinder_color;
	}
	(void)shadow_part;
	// if (shadow_part == true)
	// {
	// 	printf(CYAN"HIT_SPHERE:\n");
	// 	printf("loop_objects: %p\n", cylinder);
	// 	printf("record->object.data: %p\n", hit->object.data);
	// 	printf(DEFAULT);
	// }
	return (is_hit);
}
