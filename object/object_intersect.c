/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_intersect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 20:07:13 by tfarkas           #+#    #+#             */
/*   Updated: 2025/07/19 19:11:55 by tfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

/*
	The set_ray_opposite_normal function set the hit normal that way it
	point against the ray.
*/
void	set_ray_opposite_normal(t_ray *ray, t_hit *hit, t_vec3 normal)
{
	if (vec3_dot(ray->dir, normal) < 0)
		hit->normal = normal;
	else
		hit->normal = vec3_multiply(normal, -1.0);
}

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
	t_vec3	hit_normal;

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
	hit_normal = vec3_divide(vec3_sub_vec3(hit->hit_point,
				sphere->center), sphere_radius);
	hit->hit_color = sphere->sphere_color;
	set_ray_opposite_normal(ray, hit, hit_normal);
	return (true);
}

/*
	First check if the ray parallel with the plane. If paralel there 
	is no intersection. (during the check we need to use a small 
	epsilon value not directly compare with 0).
	rayn_planen_dot = ray_dir * plane_n
	
	After calculate the t value
	ray_p_plane_p = plane->point - ray->orign;
	t = (ray_p_plane_p * plane->unit_normal_vec) / rayn_planen_dot
	Store as hit if the t value is in te t_min t_max intervallum
*/
bool	hit_plane(t_plane *plane, t_ray *ray, t_hit *hit)
{
	double	rayn_planen_dot;
	double	t;
	t_vec3	ray_p_plane_p;

	rayn_planen_dot = vec3_dot(ray->dir, plane->unit_normal_vec);
	if (fabs(rayn_planen_dot) < EPSILON)
		return (false);

	ray_p_plane_p = vec3_sub_vec3(plane->point, ray->orign);
	t = vec3_dot(ray_p_plane_p, plane->unit_normal_vec) / rayn_planen_dot;
	if (t < hit->t_min || t > hit->t_max)
		return (false);
	hit->t = t;
	hit->hit_point = ray_at(ray, hit->t);
	hit->hit_color = plane->plane_color;
	set_ray_opposite_normal(ray, hit, plane->unit_normal_vec);
	return (true);
}
