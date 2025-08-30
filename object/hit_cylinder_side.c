/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder_side.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 17:17:41 by jisokim2          #+#    #+#             */
/*   Updated: 2025/08/30 12:15:38 by jisokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

static t_point3	get_normal(t_cylinder *cylinder
	, t_hit *hit, double height_projection)
{
	t_point3	hitpoint_height;

	hitpoint_height = vec3_plus_vec3(cylinder->center,
			vec3_multiply(cylinder->axis, height_projection));
	return (vec3_normalized(vec3_sub_vec3(hit->hit_point, hitpoint_height)));
}

static bool	is_within_cylinder_height(t_ray *ray
	, t_cylinder *cylinder, double t)
{
	t_vec3	axis_to_hit;
	double	height_projection;

	axis_to_hit = vec3_sub_vec3(ray_at(ray, t), cylinder->center);
	height_projection = vec3_dot(axis_to_hit, cylinder->axis);
	if (fabs(height_projection) > cylinder->height / 2)
	{
		return (false);
	}
	return (true);
}

static bool	calculate_cylinder_intersection(t_cylinder *cylinder
	, t_intersection *inter, t_ray *ray)
{
	t_vec3	cylinder_to_ray_origin;
	double	r;

	r = cylinder->diameter / 2;
	cylinder_to_ray_origin = vec3_sub_vec3(ray->orign, cylinder->center);
	inter->a = vec3_length_squared(vec3_cross(ray->dir, cylinder->axis));
	inter->half_b = vec3_dot(vec3_cross(ray->dir, cylinder->axis),
			vec3_cross(cylinder_to_ray_origin, cylinder->axis));
	inter->c = vec3_length_squared(vec3_cross(cylinder_to_ray_origin,
				cylinder->axis)) - r * r;
	inter->discriminant = (inter->half_b * inter->half_b)
		- (inter->a * inter->c);
	if (inter->discriminant < EPSILON)
		return (false);
	return (true);
}

static bool	is_valid_t(t_intersection *inter, t_hit *hit)
{
	inter->t = (-inter->half_b - sqrt(inter->discriminant)) / inter->a;
	if (inter->t < hit->t_min || inter->t > hit->t_max)
	{
		inter->t = (-inter->half_b + sqrt(inter->discriminant)) / inter->a;
		if (inter->t < hit->t_min || inter->t > hit->t_max)
			return (false);
	}
	return (true);
}

bool	hit_cylinder_side(t_cylinder *cylinder, t_ray *ray, t_hit *hit)
{
	t_intersection	inter;

	if (!calculate_cylinder_intersection(cylinder, &inter, ray))
		return (false);
	if (!is_valid_t(&inter, hit))
		return (false);
	if (!is_within_cylinder_height(ray, cylinder, inter.t))
		return (false);
	hit->t = inter.t;
	hit->hit_point = ray_at(ray, inter.t);
	hit->hit_color = cylinder->cylinder_color;
	hit->normal = get_normal(cylinder, hit,
			vec3_dot(vec3_sub_vec3(hit->hit_point, cylinder->center),
				cylinder->axis));
	set_ray_opposite_normal(ray, hit, hit->normal);
	uv_calculate_clyinder_side(cylinder, hit->hit_point);
	return (true);
}

// bool	hit_cylinder_side(t_cylinder *cylinder, t_ray *ray, t_hit *hit)
// {
// 	double	a;
// 	double	r;
// 	double	c;
// 	double	t;
// 	double	half_b;
// 	double	check;
// 	t_vec3	delta_p;

// 	r = cylinder->diameter / 2;
// 	delta_p = vec3_sub_vec3(ray->orign, cylinder->center);
// 	a = vec3_length_squared(vec3_cross(ray->dir, cylinder->axis));
// 	half_b = vec3_dot(vec3_cross(ray->dir, cylinder->axis), vec3_cross(delta_p, cylinder->axis));
// 	c = vec3_length_squared(vec3_cross(delta_p, cylinder->axis)) - r * r;
// 	check = half_b * half_b - a * c;
// 	if(check < EPSILON)
// 		return (false);
	
// 	t = (-half_b - sqrt(check)) / a;
// 	if (t < hit->t_min || t > hit->t_max)
// 	{
// 		t = (-half_b + sqrt(check)) / a;
// 		if (t <hit->t_min || t > hit->t_max)
// 			return (false);
// 	}

// 	//check if is in cylinder height
// 	t_vec3 hit_point = ray_at(ray, t);
// 	t_vec3 axis_to_hit = vec3_sub_vec3(hit_point, cylinder->center);
// 	double height_projection = vec3_dot(axis_to_hit, cylinder->axis);

// 	if (fabs(height_projection) > cylinder->height / 2)
// 	{
// 		return (false);
// 	}

// 	hit->t = t;
// 	hit->hit_point = hit_point;
// 	hit->hit_color = cylinder->cylinder_color;

// 	//get normal 
// 	t_point3 hitpoint_height;
	
// 	hitpoint_height = vec3_plus_vec3(cylinder->center, vec3_multiply(cylinder->axis, height_projection));
// 	hit->normal = vec3_normalized(vec3_sub_vec3(hit->hit_point, hitpoint_height));
// 	hit->normal = get_normal(cylinder, hit, height_projection);
// 	set_ray_opposite_normal(ray, hit, hit->normal);
// 	uv_calculate_clyinder_side(cylinder, hit->hit_point);
// 	return (true);
// }