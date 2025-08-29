/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 17:17:41 by jisokim2          #+#    #+#             */
/*   Updated: 2025/08/29 20:47:17 by jisokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

static t_point3	get_normal(t_cylinder *cylinder, t_hit *hit, double height_projection)
{
	t_point3 hitpoint_height;
	
	hitpoint_height = vec3_plus_vec3(cylinder->center,
		vec3_multiply(cylinder->axis, height_projection));
	return (vec3_normalized(vec3_sub_vec3(hit->hit_point, hitpoint_height)));
}

static bool	is_within_cylinder_height(t_ray *ray, t_cylinder *cylinder, double t)
{
	t_vec3 axis_to_hit = vec3_sub_vec3(ray_at(ray, t), cylinder->center);
	double height_projection = vec3_dot(axis_to_hit, cylinder->axis);
	if (fabs(height_projection) > cylinder->height / 2)
	{
		return (false);
	}
	return (true);
}

bool	hit_cylinder_side(t_cylinder *cylinder, t_ray *ray, t_hit *hit)
{
	double	a;
	double	r;
	double	c;
	double	t;
	double	half_b;
	double	check;
	t_vec3	cylinder_to_ray_origin;

	r = cylinder->diameter / 2;
	cylinder_to_ray_origin = vec3_sub_vec3(ray->orign, cylinder->center);
	a = vec3_length_squared(vec3_cross(ray->dir, cylinder->axis));
	half_b = vec3_dot(vec3_cross(ray->dir, cylinder->axis), vec3_cross(cylinder_to_ray_origin, cylinder->axis));
	c = vec3_length_squared(vec3_cross(cylinder_to_ray_origin, cylinder->axis)) - r * r;
	check = half_b * half_b - a * c;
	if(check < EPSILON)
		return (false);
	
	t = (-half_b - sqrt(check)) / a;
	if (t < hit->t_min || t > hit->t_max)
	{
		t = (-half_b + sqrt(check)) / a;
		if (t <hit->t_min || t > hit->t_max)
			return (false);
	}

	if (!is_within_cylinder_height(ray, cylinder ,t))
		return (false);
	hit->t = t;
	hit->hit_point = ray_at(ray, t);
	hit->hit_color = cylinder->cylinder_color;
	hit->normal = get_normal(cylinder, hit, vec3_dot(vec3_sub_vec3(ray_at(ray, t), cylinder->center), cylinder->axis));
	set_ray_opposite_normal(ray, hit, hit->normal);
	uv_calculate_clyinder_side(cylinder, ray_at(ray, t));
	return (true);
}

bool	hit_cylinder_cap(t_cylinder *cylinder, t_vec3 cap_center, t_ray *ray, t_hit *hit, t_vec3 cap_normal)
{
	const double r = cylinder->diameter / 2;
	double check = vec3_dot(ray->dir, cap_normal);
	if (fabs(check) < EPSILON)
	{
		return (false);
	}
	double t = vec3_dot(vec3_sub_vec3(cap_center, ray->orign), cap_normal) / check;
	if (t < hit->t_min || t > hit->t_max)
	{
		return (false);
	}
	t_point3 p = ray_at(ray, t);
	if (vec3_length_squared(vec3_sub_vec3(p, cap_center)) > r * r)
	{
		return (false);
	}
	hit->t = t;
	hit->hit_point = p;
	hit->hit_color = cylinder->cylinder_color;
	set_ray_opposite_normal(ray, hit, cap_normal);
	uv_calculate_cylinder_cap(cylinder, cap_center, cap_normal, hit->hit_point);
	return (true);	
}

bool      hit_cylinder( t_cylinder *cylinder, t_ray *ray, t_hit *hit)
{
	if (!cylinder || !ray || !hit)
		return (false);
	
    bool is_hit = false;
	double half_height = cylinder->height / 2.f;
	
    t_vec3 up = vec3_normalized(cylinder->axis);
    t_vec3 top_center = vec3_plus_vec3(cylinder->center, vec3_multiply(up, half_height));
    t_vec3 bottom_center = vec3_sub_vec3(cylinder->center, vec3_multiply(up, half_height));

	is_hit =  hit_cylinder_side(cylinder, ray, hit) ||
				hit_cylinder_cap(cylinder, bottom_center, ray, hit, vec3_multiply(up, -1.0)) ||
         		hit_cylinder_cap(cylinder, top_center, ray, hit, up);
	
    return (is_hit);
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