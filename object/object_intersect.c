/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_intersect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 20:07:13 by tfarkas           #+#    #+#             */
/*   Updated: 2025/07/10 21:15:24 by tfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

/*
	oc = sphere_center - ray_origin
*/
bool	hit_sphere(t_sphere *sphere, t_ray *ray, t_hit *hit)
{
	t_vec3	oc;

	oc = vec3_sub_vec3(sphere->center, (t_vec3)ray->orig);
}