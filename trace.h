#include "vector.h"

t_ray       ray(t_point3 orig, t_vec3 dir)
{
    t_ray ray;

    ray.orig = orig;
    ray.dir = vec3_normalized(dir);
    return (ray);
}

//ray origin point ------> ray dir * t 
t_point3    ray_at(t_ray *ray, double t)
{
    t_point3 at;

    at = vec3_plus_vec3(ray->orig, vmult(ray->dir, t));
    return (at);
}