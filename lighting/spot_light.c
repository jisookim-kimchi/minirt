/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spot_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 17:36:54 by tfarkas           #+#    #+#             */
/*   Updated: 2025/08/30 18:47:01 by tfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lighting.h"

/*
	check if the point is in the spot light cone
*/
bool	is_in_spot_cone(const t_spot_light *spot, t_vec3 point)
{
	double	angle_cosine;
	double	point_cosine;
	double	distance_to_light;
	t_vec3	light_to_point;

	if (!spot)
	{
		printf("spot light is NULL\n");
		return (false);
	}
	light_to_point = vec3_sub_vec3(point, spot->light_position);
	distance_to_light = vec3_length(light_to_point);
	if (distance_to_light > spot->distance)
		return (false);
	angle_cosine = cos(deg2rad(spot->angle) / 2);
	point_cosine = vec3_dot(vec3_normalized(light_to_point),
			vec3_normalized(spot->direction));
	if (point_cosine < angle_cosine)
		return (false);
	return (true);
}

/*
	get intersity
*/
float	spot_light_intensity_at(const t_spot_light *spot, t_vec3 point)
{
	float	intensity;
	double	angle_cosine;
	double	point_cosine;
	double	distance_to_light;
	t_vec3	light_to_point;

	if (!spot || !is_in_spot_cone(spot, point))
		return (0.0f);
	light_to_point = vec3_sub_vec3(point, spot->light_position);
	distance_to_light = vec3_length(light_to_point);
	if (distance_to_light > spot->distance)
		return (0.0f);
	angle_cosine = cos(deg2rad(spot->angle) / 2);
	point_cosine = vec3_dot(vec3_normalized(light_to_point),
			vec3_normalized(spot->direction));
	if (point_cosine < angle_cosine)
		return (0.0f);
	intensity = spot->intensity * spot->light_ratio;
	return (intensity);
}

/*
	todo : calculate fall off 
	float	spot_light_falloff(const t_spot_light *spot, t_vec3 point)
{
	if (!spot || !is_in_spot_cone(spot, point))
		return (0.0f);
	
	// Calculate the distance from the light to the point
	t_vec3 light_to_point = vec3_sub_vec3(point, spot->light.light_position);
	double distance_to_light = vec3_length(light_to_point);
	if (distance_to_light > spot->distance)
		return (0.0f);
	// Calculate the falloff based on the distance
	float falloff = distance_to_light / spot->distance;
	// Clamp the falloff value to the range 0 ~ 1
	falloff = pow(1.0f - clamp_calculation(falloff, 0.0f, 1.0f), 2.0f);
	// if (falloff < 0.0f)
	// 	falloff = 0.0f;
	return (falloff);
}
*/
float	spot_light_falloff(const t_spot_light *spot, t_vec3 point)
{
	t_vec3	light_to_point;
	double	distance_to_light;
	float	falloff;

	if (!spot || !is_in_spot_cone(spot, point))
		return (0.0f);
	light_to_point = vec3_sub_vec3(point, spot->light_position);
	distance_to_light = vec3_length(light_to_point);
	if (distance_to_light > spot->distance)
		return (0.0f);
	falloff = distance_to_light / spot->distance;
	falloff = pow(1.0f - clamp_calculation(falloff, 0.0f, 1.0f), 2.0f);
	return (falloff);
}
