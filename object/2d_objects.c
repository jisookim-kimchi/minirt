/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2d_objects.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:33:47 by tfarkas           #+#    #+#             */
/*   Updated: 2025/08/29 17:04:01 by jisokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

/*
	The plane_unit_normal_check function check if the plane normal vector is
	3d normalized unit vector. If not it return false. 
	
	To check if the input vector is 3d normalized normal vector
	it needs substract 1.0f form the input vector length absolute value
	and compare with epsilon value what we still tolerate.
*/

static bool	plane_unit_normal_check(t_vec3 *in_unit_normal_vec)
{
	*in_unit_normal_vec = vec3_normalized(*in_unit_normal_vec);
	if (fabs(vec3_length(*in_unit_normal_vec) - 1.0f) > EPSILON)
	{
		printf("%s\nThe plane input vector is not"
			" unit vector!%s\n", RED, DEFAULT);
		return (false);
	}
	return (true);
}

t_objs_list	*create_plane(t_plane *plane)
{
	t_objs_list	*new_list_member;

	if (plane_unit_normal_check(&(plane->unit_normal_vec)) == false)
		return (NULL);
	plane->has_checkboard = false;
	init_uv(&(plane->uv));
	init_material(&(plane->material));
	new_list_member = create_obj_lst_member(plane, PLANE);
	if (!new_list_member)
		return (NULL);
	return (new_list_member);
}
