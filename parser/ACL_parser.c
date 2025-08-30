/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ACL_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 16:49:02 by jisokim2          #+#    #+#             */
/*   Updated: 2025/08/30 19:05:33 by tfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	parse_ambient(char *line, t_ambient *ambient)
{
	char	**tokens;
	float	ratio;

	tokens = ft_split(line, ' ');
	if (!tokens || count_array_elem(tokens) != 3)
		return (-1);
	ratio = ft_atof(tokens[1]);
	if (ratio < 0.0 || ratio > 1.0)
	{
		return (-1);
	}
	parse_color(tokens[2], &ambient->ambient_color.red,
		&ambient->ambient_color.green, &ambient->ambient_color.blue);
	ambient->ambient_ratio = ratio;
	free_splited_str(tokens);
	return (1);
}

int	parse_spot_light(const char *line, t_spot_light *light)
{
	char	**tokens;

	tokens = ft_split(line, ' ');
	if (!tokens || count_array_elem(tokens) != 9)
		return (-1);
	parse_vec3(tokens[1], &light->light_position.x,
		&light->light_position.y, &light->light_position.z);
	light->light_ratio = ft_atof(tokens[2]);
	if (!check_value_in_range(light->light_ratio, 0.0, 1.0))
		return (-1);
	parse_color(tokens[3], &light->light_color.red,
		&light->light_color.green, &light->light_color.blue);
	light->is_light = true;
	parse_vec3(tokens[4], &light->direction.x,
		&light->direction.y, &light->direction.z);
	light->intensity = ft_atof(tokens[5]);
	light->radius = ft_atof(tokens[6]);
	light->angle = ft_atof(tokens[7]);
	light->distance = ft_atof(tokens[8]);
	free_splited_str(tokens);
	return (1);
}

int	parse_light(char *line, t_light *light)
{
	char	**tokens;

	tokens = ft_split(line, ' ');
	if (!tokens || count_array_elem(tokens) != 4)
		return (-1);
	parse_vec3(tokens[1], &light->light_position.x,
		&light->light_position.y, &light->light_position.z);
	light->light_ratio = ft_atof(tokens[2]);
	if (!check_value_in_range(light->light_ratio, 0.0, 1.0))
		return (-1);
	parse_color(tokens[3], &light->light_color.red,
		&light->light_color.green, &light->light_color.blue);
	light->is_light = true;
	free_splited_str(tokens);
	return (1);
}

static void	set_camera_orientation(t_camera *camera)
{
	if (fabs(vec3_dot(camera->transform_comp.forward,
				vec3(0.0, 1.0, 0.0))) > 0.999f)
		camera->transform_comp.right = vec3_cross
			(camera->transform_comp.forward, (t_vec3){0, 0, 1});
	else
		camera->transform_comp.right = vec3_cross
			(camera->transform_comp.forward, (t_vec3){0, 1, 0});
	camera->transform_comp.up = vec3_cross
		(camera->transform_comp.right, camera->transform_comp.forward);
}

int	parse_camera(char *line, t_camera *camera)
{
	char	**tokens;
	float	fov;

	tokens = ft_split(line, ' ');
	if (!tokens || count_array_elem(tokens) != 4)
		return (-1);
	parse_vec3(tokens[1], &camera->transform_comp.transform.position.x,
		&camera->transform_comp.transform.position.y,
		&camera->transform_comp.transform.position.z);
	parse_vec3(tokens[2], &camera->transform_comp.forward.x,
		&camera->transform_comp.forward.y,
		&camera->transform_comp.forward.z);
	fov = ft_atof(tokens[3]);
	if (fov < 0 || fov > 180)
		return (-1);
	camera->transform_comp.forward = vec3_normalized
		(camera->transform_comp.forward);
	set_camera_orientation(camera);
	camera->fov = fov;
	free_splited_str(tokens);
	return (1);
}
