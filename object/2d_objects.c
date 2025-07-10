/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2d_objects.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:33:47 by tfarkas           #+#    #+#             */
/*   Updated: 2025/07/10 17:03:03 by tfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_objs_list	*create_plane(t_vec3 in_unit_normal_vec, 
	t_vec3 in_point, t_color_float in_plane_color)
{
	t_plane		*new_plane;
	t_objs_list	*new_list_member;

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
