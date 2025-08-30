/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 16:55:39 by jisokim2          #+#    #+#             */
/*   Updated: 2025/08/30 18:02:08 by jisokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathheader.h"

t_transform	init_transform(void)
{
	t_transform	t;

	t.position = (t_vec3){0.f, 0.f, 0.f};
	return (t);
}

// t_transform	init_transform(void)
// {
// 	t_transform	t;

// 	t.position = (t_vec3){0.f, 0.f, 0.f};
// 	//t.rotation = init_quaternion();
// 	t.scale = (t_vec3){1.f, 1.f, 1.f};
// 	return (t);
// }

// t_transform	make_transform_pos_rot_scale(const t_vec3 *pos,
// 	const t_quaternion *rot, const t_vec3 *scale)
// {
// 	t_transform	t;

// 	t.position = *pos;
// 	t.rotation = *rot;
// 	t.scale = *scale;
// 	return (t);
// }

void	add_position(t_transform *transform, t_vec3 *in_deltapos)
{
	vec3_plus_vec3(transform->position, *in_deltapos);
}

void	set_position(t_transform *transform, t_vec3 *in_pos)
{
	transform->position.x = in_pos->x;
	transform->position.y = in_pos->y;
	transform->position.z = in_pos->z;
}

t_vec3	get_position(t_transform *transform)
{
	return (transform->position);
}

/*
	quaternion -> rotation.
	rotation -> quaternion.
*/

// void    add_yaw_rot(t_transform *transform, float in_degree)
// {
//     t_rotator r = transform.rotation.to_rotator();
//     r.yaw += in_degree;
//     clamp(&r);
//     transform.rotation = quaternion(r);
// }

// void    add_pitch_rot(t_transform *transform, float in_degree)
// {
//     t_rotator r = transform->rotation.to_rotator();
//     r.pitch += in_degree;
//     r.
// }

// t_transform	make_transform_pos(const t_vec3 *position)
// {
// 	t_transform	t;

// 	t.position = *position;
// 	t.rotation = init_quaternion();
// 	t.scale = vec3_one();
// 	return (t);
// }

// t_transform	make_transform_rot(const t_quaternion *in_rot,
//									const t_vec3 *in_pos)
// {
// 	t_transform	t;
// 	t.position = *in_pos;
// 	t.rotation = *in_rot;
// 	t.scale = vec3_one();
// 	return (t);
// }