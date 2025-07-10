/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_objects.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:07:51 by tfarkas           #+#    #+#             */
/*   Updated: 2025/07/10 17:19:41 by tfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_objs_list	*create_sphere(t_vec3 in_center, 
	float in_diameter, t_color_float in_sphere_color)
{
	t_sphere		*new_sphere;
	t_objs_list	*new_list_member;

	new_sphere = (t_sphere *)malloc(sizeof(t_sphere));
	if (!new_sphere)
	{
		perror("Failed to allocate memory for new sphere");
		return (NULL);
	}
	new_list_member = (t_objs_list *)malloc(sizeof(t_objs_list));
	if (!new_list_member)
	{
		perror("Failed to allocate memory for new object");
		return (free(new_sphere), NULL);
	}
	new_sphere->center = in_center;
	new_sphere->diameter = in_diameter;
	new_sphere->sphere_color = in_sphere_color;
	new_list_member->obj_type = SPHERE;
	new_list_member->data = new_sphere;
	new_list_member->next = NULL;
	return (new_list_member);
}
