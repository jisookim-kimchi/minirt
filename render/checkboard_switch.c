/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkboard_switch.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 08:15:15 by tfarkas           #+#    #+#             */
/*   Updated: 2025/09/02 08:34:25 by tfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_tools.h"

void	checkboard_switch_on(t_objs_list *object, bool is_on)
{
	if (object->obj_type == SPHERE)
	{
		object->has_checkerboard = is_on;
	}
	else if (object->obj_type == PLANE)
	{
		object->has_checkerboard = is_on;
	}
	else if (object->obj_type == CYLINDER)
	{
		object->has_checkerboard = is_on;
	}
}

void	check_on_all_obj(t_window *win, bool is_on)
{
	t_objs_list	*current;

	current = win->objs;
	while (current)
	{
		checkboard_switch_on(current, is_on);
		current = current->next;
	}
}
