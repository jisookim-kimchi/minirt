/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 19:20:19 by tfarkas           #+#    #+#             */
/*   Updated: 2025/07/14 15:00:33 by tfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

void	change_member_in_list(t_objs_list **list, t_objs_list *old_member, t_objs_list *new_member)
{
	t_objs_list	*temp;

	temp = *list;
	
}

// add a node at tail.
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
//jisoo's suggestion
void	free_objs_list(t_objs_list **list)
{
	t_objs_list	*current;

	if (!list || !*list)
		return ;
	while ((*list))
	{
		current = (*list)->next;
		free(*list);
		*list = current;
	}
	*list = NULL;
}


// void	free_objs_list(t_objs_list **list)
// {
// 	t_objs_list	*current;

// 	while ((*list)->next)
// 	{
// 		current = (*list)->next;
// 		free(*list);
// 		*list = current;
// 	}
// 	free(list);
// 	list = NULL;
// }

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

/*
	The get_hittable_list function check for all of the object if it is hit by the ray.
	It will give the hittable_list, if in the hittable_list already doesn't 
	exist an object which is hited by the ray and it is closer to the ray origin
*/
t_hittable_objs	get_hittable_list(t_objs_list *obj, t_ray *ray, t_hit *hit)
{
	t_hittable_objs	hittable_list;

	hittable_list = NULL;
	while (obj->next)
	{
		if (ray_intersect(obj, ray, hit) == true)
		{
			if (hit)
			{
				add_member_to_obj_list(hittable_list, obj);
			}
		}
		obj = obj->next;
	}
	return (hittable_list);
}

void	print_objs(t_objs_list *obj)
{
	t_objs_list *cur;

	cur = obj;
	while (cur)
	{
		if (cur->obj_type == PLANE)
			printf("current object is PLANE\n");
		else if (cur->obj_type == CYLINDER)
			printf("current object is CYLINDER\n");
		else if (cur->obj_type == SPHERE)
			("current object is SPHERE\n");
		cur = cur->next;
	}
}