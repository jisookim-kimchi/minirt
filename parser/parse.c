/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 14:17:59 by jisokim2          #+#    #+#             */
/*   Updated: 2025/07/29 16:53:26 by jisokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
/*
	todo change name
	check each line and validate weather its requiered params
*/
int	parsing_start(char *line, t_window *window)
{
	if (ft_strncmp(line, "A", 1) == 0)
	{
		if (parse_ambient(line, &window->ambient) == -1)
		{
			return (-1);
		}
		else
		{
			printf("ambient color : %f, %f, %f\n", window->ambient.ambient_color.red, window->ambient.ambient_color.green, window->ambient.ambient_color.blue);
			printf("ambient_color %p\n", &window->ambient.ambient_color);
			printf("ambient ratio : %f\n", window->ambient.ambient_ratio);
		}
	}
	else if (ft_strncmp(line, "C", 1) == 0)
	{
		printf("camera parsing start\n");
		if (parse_camera(line, &window->camera) == -1)
		{
			printf("camera issue\n");
			return (-1);
		}
		else
		{
			printf("camera position : %f, %f, %f\n", window->camera.transform_comp.transform->position.x, window->camera.transform_comp.transform->position.y, window->camera.transform_comp.transform->position.z);
		}
	}
	else if (ft_strncmp(line, "L", 1) == 0)
	{
		printf("light parsing_start\n");
		if (parse_light(line, &window->light) == -1)
			return (-1);
		else
		{
			printf("light color : %f, %f, %f\n", window->light.light_color.red, window->light.light_color.green, window->light.light_color.blue);
			printf("light position : %f, %f, %f\n", window->light.light_position.x, window->light.light_position.y, window->light.light_position.z);
			printf("light ratio : %f\n", window->light.light_ratio);
		}
	}
	else if (ft_strncmp(line, "sp", 2) == 0)
		printf("Sphere\n");
	else if (ft_strncmp(line, "pl", 2) == 0)
		printf("Plane\n");
	else if (ft_strncmp(line, "cy", 2) == 0)
		printf("Cylinder\n");
	else
		return (-1);
	return (1);
}

/*
	check if it has minimum components for rendering.
*/
// int	has_minimum_components()
// {
		
// }
