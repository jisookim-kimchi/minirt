/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spot_light_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 18:05:23 by tfarkas           #+#    #+#             */
/*   Updated: 2025/08/30 18:41:52 by tfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lighting.h"

t_objs_list	*create_spotlight(t_spot_light *spotlight)
{
	t_objs_list		*new_list_member;

	new_list_member = create_obj_lst_member(spotlight, SPOTLIGHT);
	if (!new_list_member)
		return (NULL);
	return (new_list_member);
}
/*
	t_spot_light	init_spot_light(t_spot_light *light, t_vec3 direction, float distance, float angle, float intensity)
	{
		t_spot_light	spot_light;

		if (distance <= 0 || angle <= 0 || intensity <= 0)
		{
			printf("Wrong input for point_light so we give DEFAULT point_light\n");
			spot_light.light_position = light->light_position;
			spot_light.light_ratio = light->light_ratio;
			spot_light.light_color = light->light_color;
			spot_light.angle = 60.f;
			spot_light.distance = 500.f;
			spot_light.direction = (t_vec3){0, -1, 0};
			spot_light.intensity = 2.f;
			return (spot_light);
		}
		spot_light.light_position = light->light_position;
		spot_light.light_ratio = light->light_ratio;
		spot_light.light_color = light->light_color;
		set_spot_direction(&spot_light, direction);
		spot_light.distance = distance;
		spot_light.angle = angle;
		spot_light.intensity = intensity;
		return (spot_light);
	}
*/


//to set direction for spot light
void	set_spot_direction(t_spot_light *spot, t_vec3 direction)
{
	if (!spot)
	{
		printf("spot light is NULL\n");
		return ;
	}
	spot->direction = vec3_normalized(direction);
}
