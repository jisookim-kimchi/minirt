/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_objects.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:07:51 by tfarkas           #+#    #+#             */
/*   Updated: 2025/08/29 16:32:35 by jisokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_objs_list	*create_sphere(t_sphere *sphere)
{
	t_objs_list		*new_list_member;

	sphere->has_checkboard = false;
	init_material(&(sphere->material));
	init_uv(&(sphere->uv));
	new_list_member = create_obj_lst_member(sphere, SPHERE);
	if (!new_list_member)
		return (NULL);
	return (new_list_member);
}

t_objs_list	*create_cylinder(t_cylinder *cylinder)
{
	t_objs_list		*new_list_member;

	cylinder->has_checkboard = false;
	cylinder->is_side_hit = false;
	cylinder->is_bottomcap_hit = false;
	cylinder->is_topcap_hit = false;
	init_material(&(cylinder->material));
	init_uv(&(cylinder->cap_uv));
	init_uv(&(cylinder->side_uv));
	new_list_member = create_obj_lst_member(cylinder, CYLINDER);
	if (!new_list_member)
		return (NULL);
	return (new_list_member);
}
