/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_intersect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 20:07:13 by tfarkas           #+#    #+#             */
/*   Updated: 2025/07/11 12:56:48 by tfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

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

	sphere_radius = (double)((sphere->diameter) / 2);
	oc = vec3_sub_vec3(sphere->center, (t_vec3)ray->orig);
	a = vec3_length_squared(ray->dir);
	h = vec3_dot(ray->dir, oc);
	c = vec3_length_squared(oc) - sphere_radius * sphere_radius;
	discriminant = h * h - a * c;
}