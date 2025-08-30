#include "objects.h"

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
	t_vec3 down = vec3_multiply(up, -1.0);
    t_vec3 top_center = vec3_plus_vec3(cylinder->center, vec3_multiply(up, half_height));
    t_vec3 bottom_center = vec3_plus_vec3(cylinder->center, vec3_multiply(down, half_height));

	is_hit =  hit_cylinder_side(cylinder, ray, hit) || hit_cylinder_cap(cylinder, top_center, ray, hit, up)
				|| hit_cylinder_cap(cylinder, bottom_center, ray, hit, down);
	
	if (is_hit)
	{
		hit->object.obj_type = CYLINDER;
		hit->object.data = cylinder;
		hit->hit_color = cylinder->cylinder_color;
	}
				
    return (is_hit);
}