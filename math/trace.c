/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 16:24:49 by jisokim2          #+#    #+#             */
/*   Updated: 2025/08/30 16:25:48 by jisokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathheader.h"

t_ray	create_ray(t_point3 orig, t_vec3 dir)
{
	t_ray	ray;

	ray.orign = orig;
	ray.dir = vec3_normalized(dir);
	return (ray);
}

/*
    ray origin point ------> ray dir * t
    from [ray_origin] point to [ray->dir * t]
*/
t_point3	ray_at(t_ray *ray, double t)
{
	t_point3	at;

	at = vec3_plus_vec3(ray->orign, vec3_multiply(ray->dir, t));
	return (at);
}
