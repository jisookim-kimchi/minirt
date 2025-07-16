/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_intersect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 20:07:13 by tfarkas           #+#    #+#             */
/*   Updated: 2025/07/16 19:59:09 by tfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

/*
	The set_hit_sphere_point function will giv the object to
	the hittable objects list just that case if it is 
	in the investigated ray intervallum.

	TODO:
	The t minimum and maximum value stored in hit structure. 
	Still need to initialize with the desired ray intervallum
*/
static bool	set_hit_sphere_point(float t_root1, float t_root2, t_hit *hit)
{
	if (t_root1 < t_root2 && check_value_in_range(t_root1, hit->t_min, hit->t_max))
		hit->t = t_root1;
	else if (check_value_in_range(t_root2, hit->t_min, hit->t_max))
		hit->t = t_root2;
	else
		return (false);
	return (true);
}

/*
	oc = sphere_center - ray_origin
	b = -2h simplified qadratic equation solving formula exponents:
	a = ray direction vector length squared
	h = dot product of ray direction vector and oc vector
	c = leng squared of oc vector substract the sphere's radius square
	discriminant = h * h - a * c

	the calculation made in double variable datatype
*/
bool	hit_sphere(t_sphere *sphere, t_ray *ray, t_hit *hit)
{
	t_vec3	oc;
	double	sphere_radius;
	float	t_root1;
	float	t_root2;
	double	a;
	double	h;
	double	c;
	double	discriminant;

	sphere_radius = (double)((sphere->diameter) / 2);
	oc = vec3_sub_vec3(sphere->center, (t_vec3)ray->orign);
	a = vec3_length_squared(ray->dir);
	h = vec3_dot(ray->dir, oc);
	c = vec3_length_squared(oc) - sphere_radius * sphere_radius;
	discriminant = h * h - a * c;
	if (discriminant < 0)
		return (false);
	t_root1 = (float)((h - sqrt(discriminant)) / a);
	t_root2 = (float)((h + sqrt(discriminant)) / a);
	if (set_hit_sphere_point(t_root1, t_root2, hit) == false)
		return (false);
	hit->hit_point = ray_at(ray, hit->t);
	hit->normal = vec3_divide(vec3_sub_vec3(hit->hit_point,
				sphere->center), sphere_radius);
	return (true);
}
