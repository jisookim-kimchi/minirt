/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 14:17:59 by jisokim2          #+#    #+#             */
/*   Updated: 2025/07/29 15:37:18 by jisokim2         ###   ########.fr       */
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
			printf("123\n");
			return (-1);
		}
		else
		{
			printf("ambient color : %f, %f, %f\n", window->ambient.ambient_color.red, window->ambient.ambient_color.green, window->ambient.ambient_color.blue);
			printf("ambient ratio : %f\n", window->ambient.ambient_ratio);
		}
	}
	else if (ft_strncmp(line, "C", 1) == 0)
	{
		if (parse_camera(line, &window->camera) == -1)
			return (-1);
	}
	else if (ft_strncmp(line, "L", 1) == 0)
	{
		if (parse_light(line, &window->light) == -1)
			return (-1);
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
