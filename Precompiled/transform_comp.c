/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_comp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 15:35:25 by jisokim2          #+#    #+#             */
/*   Updated: 2025/08/30 18:02:45 by jisokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loadresource.h"

//need to make init transform_comp.c
/*
	at scene passer we need to set appropriated rocation of objects
	for the futur we can add 
	transform_comp.transform.rotation = init_quaternion();
*/
// t_transform_comp	init_transform_comp(void)
// {
// 	t_transform_comp	transform_comp;

// 	transform_comp.transform.position = vec3(0, 0, 0);
// 	transform_comp.transform.scale = vec3(1, 1, 1);
// 	transform_comp.forward = vec3(0, 0, 1);
// 	transform_comp.up = vec3(0, 1, 0);
// 	transform_comp.right = vec3(1, 0, 0);
// 	return (transform_comp);
// }

t_transform_comp	init_transform_comp(void)
{
	t_transform_comp	transform_comp;

	transform_comp.transform.position = vec3(0, 0, 0);
	transform_comp.forward = vec3(0, 0, 1);
	transform_comp.up = vec3(0, 1, 0);
	transform_comp.right = vec3(1, 0, 0);
	return (transform_comp);
}

void	set_transform_comp_position(t_transform_comp *comp, t_vec3 pos)
{
	comp->transform.position = pos;
}

void	add_transform_comp_position(t_transform_comp *comp, t_vec3 delta)
{
	comp->transform.position = vec3_plus_vec3(comp->transform.position, delta);
}

t_transform	*get_world_transform(t_transform_comp *transform_comp)
{
	return (&transform_comp->transform);
}

t_vec3	get_world_position(t_transform_comp *transform_comp)
{
	return (transform_comp->transform.position);
}
