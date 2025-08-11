/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2d_objects.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:33:47 by tfarkas           #+#    #+#             */
/*   Updated: 2025/08/11 13:15:00 by jisokim2         ###   ########.fr       */
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

t_objs_list	*create_plane(t_vec3 in_unit_normal_vec, 
	t_vec3 in_point, t_color_float in_plane_color)
{
	t_plane		*new_plane;
	t_objs_list	*new_list_member;

	if (plane_unit_normal_check(&in_unit_normal_vec) == false)
		return (NULL);
	new_plane = (t_plane *)malloc(sizeof(t_plane));
	if (!new_plane)
	{
		perror("Failed to allocate memory for new plane");
		return (NULL);
	}
	new_list_member = (t_objs_list *)malloc(sizeof(t_objs_list));
	if (!new_list_member)
	{
		perror("Failed to allocate memory for new object");
		return (free(new_plane), NULL);
	}
	new_plane->unit_normal_vec = in_unit_normal_vec;
	new_plane->point = in_point;
	new_plane->plane_color = in_plane_color;
	new_list_member->obj_type = PLANE;
	new_list_member->data = new_plane;
	new_list_member->next = NULL;
	return (new_list_member);
}
