/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_intersect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 20:07:13 by tfarkas           #+#    #+#             */
/*   Updated: 2025/07/22 18:46:09 by jisokim2         ###   ########.fr       */
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
	//printf("rayn_planen_dot %f\n", rayn_planen_dot);

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

/*
	a : ray direction vector length squared
	r : half diameter

	c_dir : cylinder axis vector
	ray_dir : ray direction vector

	1. get a t value for the intersection point
	2. check if its in the cylinder height.
	3. set the hit point, color and normal.

	4. Handle intersection with cylinder caps (top & bottom)
	5. Compute correct normal for cap intersections

*/
bool	hit_cylinder_side(t_cylinder *cylinder, t_ray *ray, t_hit *hit)
{
	double	a;
	double	r;
	double	half_b;

	t_vec3	ray_dir;
	t_vec3	delta_p;

	ray_dir = ray->dir;
	r = cylinder->diameter / 2;
	delta_p = vec3_sub_vec3(ray->orign, cylinder->center);
	a = vec3_length_squared(vec3_cross(ray_dir, cylinder->axis));
	half_b = vec3_dot(vec3_cross(ray_dir, cylinder->axis), vec3_cross(delta_p, cylinder->axis));
	double c = vec3_length_squared(vec3_cross(ray_dir, cylinder->axis)) - r * r;
	double	check = (half_b * half_b) - (a * c);
	if(check < 0)
		return (false);
	
	double t = (-half_b - sqrt(check)) / a;
	if (t < hit->t_min || t > hit->t_max)
	{
		t = (-half_b + sqrt(check)) / a;
		if (t <hit->t_min || t > hit->t_max)
			return (false);
		//return (false);
	}

	//check if is in cylinder height
	t_vec3 hit_point = ray_at(ray, t);
	t_vec3 axis_to_hit = vec3_sub_vec3(hit_point, cylinder->center);
	double height_projection = vec3_dot(axis_to_hit, cylinder->axis);
	
	//todo cehck height_projection < 0 is correct
	// if (height_projection < 0 || height_projection > cylinder->height)
	// 	return (false);
	if (fabs(height_projection) > cylinder->height / 2)
	{
		return (false);
	}

	hit->t = t;
	hit->hit_point = hit_point;
	hit->hit_color = cylinder->cylinder_color;

	//get normal 
	t_point3 hitpoint_height;
    t_vec3 normal;

	hitpoint_height = vec3_plus_vec3(cylinder->center, vec3_multiply(cylinder->axis, height_projection));
	normal = vec3_sub_vec3(hit->hit_point, hitpoint_height);
	hit->normal = vec3_normalized(normal);
	set_ray_opposite_normal(ray, hit, hit->normal);
	
	return (true);
}

bool	hit_cylinder_cap(t_cylinder *cylinder, t_vec3 cap_center, t_ray *ray, t_hit *hit, t_vec3 cap_normal)
{
    const double r = cylinder->diameter / 2;
    // const t_vec3 cap_center = vec3_plus_vec3(cylinder->center, vec3_multiply(cylinder->axis, cylinder->height));

	//check if the ray is parallel to the cap plane
	double check = vec3_dot(ray->dir, cylinder->axis);
	if (fabs(check) < EPSILON)
		return (false);

	//calculate the t value for the intersection point on the cap
	double t = vec3_dot(vec3_sub_vec3(cap_center, ray->orign), cap_normal) / check;
	if (t < hit->t_min || t > hit->t_max)
		return (false);
	
	t_point3 p = ray_at(ray, hit->t);
	
	//check if it is within the cylinder's cap radius
	if (vec3_length_squared(vec3_sub_vec3(p, cap_center)) > r * r)
		return (false);
	
	hit->t = t;
	hit->hit_point = p;
	hit->hit_color = cylinder->cylinder_color;
	set_ray_opposite_normal(ray, hit, cap_normal);
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

