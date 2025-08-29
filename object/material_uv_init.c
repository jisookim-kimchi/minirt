/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material_uv_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 16:10:57 by jisokim2          #+#    #+#             */
/*   Updated: 2025/08/29 16:32:56 by jisokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

void	init_uv(t_uv *uv)
{
	uv->tile_scale = 0.0;
	uv->u = 0.0;
	uv->v = 0.0;
}

void	init_material(t_material *material)
{
	material->bump = NULL;
	material->diffuse = NULL;
	material->normal = NULL;
}
