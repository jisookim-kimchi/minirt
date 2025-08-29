/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2d_3d_objects_helper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 14:20:31 by jisokim2          #+#    #+#             */
/*   Updated: 2025/08/29 16:32:21 by jisokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_objs_list	*create_obj_lst_member(void *obj, int obj_type)
{
	t_objs_list	*new_list_member;

	new_list_member = (t_objs_list *)malloc(sizeof(t_objs_list));
	if (!new_list_member)
	{
		perror("Failed to allocate memory for new object");
		return (NULL);
	}
	new_list_member->obj_type = obj_type;
	new_list_member->data = obj;
	new_list_member->next = NULL;
	new_list_member->has_checkerboard = false;
	return (new_list_member);
}
