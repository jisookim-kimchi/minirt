/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_comp_helper.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 15:32:14 by jisokim2          #+#    #+#             */
/*   Updated: 2025/08/30 15:34:38 by jisokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loadresource.h"

t_vec3	get_forward_vector(t_transform_comp transform_comp)
{
	return (transform_comp.forward);
}

t_vec3	get_right_vector(t_transform_comp transform_comp)
{
	return (transform_comp.right);
}

t_vec3	get_up_vector(t_transform_comp transform_comp)
{
	return (transform_comp.up);
}
