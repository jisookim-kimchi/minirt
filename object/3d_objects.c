/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_objects.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:07:51 by tfarkas           #+#    #+#             */
/*   Updated: 2025/07/15 17:26:35 by jisokim2         ###   ########.fr       */
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
	new_sphere->obj_fill = SOLID;
	new_list_member->obj_type = SPHERE;
	new_list_member->data = new_sphere;
	new_list_member->next = NULL;
	return (new_list_member);
}

t_objs_list	*create_cylinder(t_vec3 in_axis, 
	float in_diameter, float in_height, t_color_float in_cylinder_color)
{
	t_cylinder		*new_cylinder;
	t_objs_list		*new_list_member;

	new_cylinder = (t_cylinder *)malloc(sizeof(t_cylinder));
	if (!new_cylinder)
	{
		perror("Failed to allocate memory for new cylinder");
		return (NULL);
	}
	new_list_member = (t_objs_list *)malloc(sizeof(t_objs_list));
	if (!new_list_member)
	{
		perror("Failed to allocate memory for new object");
		return (free(new_cylinder), NULL);
	}
	new_cylinder->axis = in_axis;
	new_cylinder->diamater = in_diameter;
	new_cylinder->height = in_height;
	new_cylinder->cylinder_color = in_cylinder_color;
	new_cylinder->obj_fill = SOLID;
	new_list_member->obj_type = CYLINDER;
	new_list_member->data = new_cylinder;
	new_list_member->next = NULL;
	return (new_list_member);
}
