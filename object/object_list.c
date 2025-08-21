/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 19:20:19 by tfarkas           #+#    #+#             */
/*   Updated: 2025/08/21 14:54:36 by jisokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"
#include "../debug/debug.h"

// add a node at tail.
void	add_member_to_obj_list(t_objs_list **list, t_objs_list *new_member)
{
	t_objs_list	*current;

	if (!list)
	{
		ft_putendl_fd("The object list in add_member_to_obj_list is NULL", 2);
		return ;
	}
	if (!new_member)
	{
		ft_putendl_fd("The new object member in "
			"add_member_to_obj_list is NULL", 2);
		return ;
	}
	if (!(*list))
	{
		*list = new_member;
	}
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

	if (!list || !*list)
		return ;
	while ((*list))
	{
		current = (*list)->next;
		free((*list)->data);
		free(*list);
		*list = current;
	}
	*list = NULL;
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

/*
	The hit_world function loop over all of the object in the object list.
	Check if the ray hit any of the object.
	The temporary hit structure t_max value will always refresh with the
	founded hit object t value. This way it will found a hit if the new 
	object closer to the ray origin, than the previous one.
*/
bool	hit_world(t_ray *ray, t_hit *record, t_objs_list *objects)
{
	bool		found_hit;
	t_objs_list	*loop_objects;
	t_hit		temp;

	if (!ray || !record || !objects)
	{
		printf("Error : NULL PTR in hit_world\n");
		return (false);
	}
	temp.t_max = record->t_max;
	found_hit = false;
	loop_objects = objects;

	while (loop_objects)
	{
		if ((loop_objects->data != record->object.data) && ray_intersect(loop_objects, ray, &temp))
		{
			// w
			found_hit = true;
			temp.t_max = temp.t;
			*record = temp;
		}
		loop_objects = loop_objects->next;
	}
	return (found_hit);
}

/*
	The get_hittable_list function check for all of the object if it is hit by the ray.
	It will give the hittable_list, if in the hittable_list already doesn't 
	exist an object which is hited by the ray and it is closer to the ray origin
*/
t_hittable_objs	*get_hittable_list(t_objs_list *obj, t_ray *ray, t_hit *hit)
{
	t_hittable_objs	*hittable_list;

	hittable_list = NULL;
	while (obj->next)
	{
		if (ray_intersect(obj, ray, hit) == true)
		{
			if (hit)
			{
				// printf("GREEN\n");
				// printf("hit\n");
				// printf("DEFAULT\n");
				add_member_to_obj_list(&hittable_list, obj);
			}
		}
		obj = obj->next;
	}
	return (hittable_list);
}

void	set_ray_interval(t_hit *hit, float set_t_min, float set_t_max)
{
	hit->t_min = set_t_min;
	hit->t_max = set_t_max;
}
