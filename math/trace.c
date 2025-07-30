#include "mathheader.h"

t_ray       create_ray(t_point3 orig, t_vec3 dir)
{
    t_ray ray;

    ray.orign = orig;
    ray.dir = vec3_normalized(dir);
    return (ray);
}

/*
    ray origin point ------> ray dir * t
    from [ray_origin] point to [ray->dir * t]
*/
t_point3    ray_at(t_ray *ray, double t)
{
    t_point3 at;

    at = vec3_plus_vec3(ray->orign, vec3_multiply(ray->dir, t));
    return (at);
}