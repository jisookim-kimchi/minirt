/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkboard.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 17:48:16 by tfarkas           #+#    #+#             */
/*   Updated: 2025/08/29 18:30:44 by tfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_tools.h"

static t_color_float	white_black_return(float *u_scaled,
	float *v_scaled, t_color_float white, t_color_float black)
{
	int	u_int;
	int	v_int;

	u_int = (int)floor(*u_scaled);
	v_int = (int)floor(*v_scaled);
	if ((u_int + v_int) % 2 == 0)
		return (white);
	else
		return (black);
}

static void	cylinder_checkboard(t_hit *hit, float *u_scaled,
	float *v_scaled)
{
	t_cylinder	*cylinder;

	cylinder = (t_cylinder *)hit->object.data;
	if (cylinder->is_topcap_hit || cylinder->is_bottomcap_hit)
	{
		*u_scaled = cylinder->cap_uv.u * cylinder->cap_uv.tile_scale;
		*v_scaled = cylinder->cap_uv.v * cylinder->cap_uv.tile_scale;
	}
	else if (cylinder->is_side_hit)
	{
		*u_scaled = cylinder->side_uv.u * cylinder->side_uv.tile_scale;
		*v_scaled = cylinder->side_uv.v * cylinder->side_uv.tile_scale;
	}
}

//TODO look at it !
t_color_float	checkboard_pattern(t_hit *hit,
	t_color_float white, t_color_float black)
{
	float		u_scaled;
	float		v_scaled;
	t_sphere	*sphere;
	t_plane		*plane;

	u_scaled = 0.0;
	v_scaled = 0.0;
	if (hit->object.obj_type == SPHERE)
	{
		sphere = (t_sphere *)hit->object.data;
		u_scaled = sphere->uv.u * sphere->uv.tile_scale;
		v_scaled = sphere->uv.v * sphere->uv.tile_scale;
	}
	if (hit->object.obj_type == PLANE)
	{
		plane = (t_plane *)hit->object.data;
		u_scaled = plane->uv.u * plane->uv.tile_scale;
		v_scaled = plane->uv.v * plane->uv.tile_scale;
	}
	if (hit->object.obj_type == CYLINDER)
		cylinder_checkboard(hit, &u_scaled, &v_scaled);
	return (white_black_return(&u_scaled, &v_scaled, white, black));
}
