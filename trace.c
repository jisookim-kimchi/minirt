#include "Precompiled/loadresource.h"

t_ray   ray(t_point3 orign, t_vec3 dir)
{
    t_ray ray;

    ray.orign = orign;
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

/*
    We want to get the direction from the camera to a point on the viewport.
    That point is calculated by:
        left_bottom_corner + u * horizontal + v * vertical.
    When we draw something on it, we gonna do mapping 1~0, this is UV
*/
t_ray   from_camera_ray(t_camera *camera, double u, double v)
{
    t_ray   ray;

    ray.orign = camera->transform_comp.transform->position;

    ray.dir = vec3_normalized(vec3_sub_vec3(vec3_plus_vec3(vec3_plus_vec3(camera->left_bottom, vec3_multiply(camera->horizontal, u)), vec3_multiply(camera->vertical, v)), camera->transform_comp.transform->position));
    return (ray);
}

