/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 19:20:19 by tfarkas           #+#    #+#             */
/*   Updated: 2025/07/10 20:05:12 by tfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

void	add_member_to_obj_list(t_objs_list **list, t_objs_list *new_member)
{
	t_objs_list	*current;

	if (!(*list))
		*list = new_member;
	else
	{
		current = *list;
		while (current->next)
			current = current->next;
		current->next = new_member;
	}
}

void	free_objs_list(t_objs_list **list)
{
	t_objs_list	*current;

	while ((*list)->next)
	{
		current = (*list)->next;
		free(*list);
		list = current;
	}
	free(list);
	list = NULL;
}

bool	ray_intersect(t_objs_list *obj, t_ray *ray, t_hit *hit)
{
	if (obj->obj_type == PLANE)
		return (hit_plane((t_plane *)obj->data, ray, hit));
	if (obj->obj_type == SPHERE)
		return (hit_sphere((t_sphere *)obj->data, ray, hit));
	if (obj->obj_type == CYLINDER)
		return (hit_cylinder((t_cylinder *)obj->data, ray, hit));
	return (false);
}
