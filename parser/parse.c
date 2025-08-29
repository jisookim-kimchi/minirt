/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 14:17:59 by jisokim2          #+#    #+#             */
/*   Updated: 2025/08/29 16:30:16 by jisokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
/*
	todo change name
	check each line and validate weather its requiered params
*/

static int	handle_sphere(const char *line, t_window *window)
{
	t_sphere	*sphere;
	t_objs_list	*obj;

	sphere = malloc(sizeof(t_sphere));
	if (!sphere || parse_sphere(line, sphere) == -1)
	{
		return (-1);
	}
	obj = create_sphere(sphere);
	if (!obj)
	{
		printf("Failed to create object\n");
		free(sphere);
		return (-1);
	}
	add_member_to_obj_list(&window->objs, obj);
	return (1);
}

static int	handle_plane(const char *line, t_window *window)
{
	t_plane		*plane;
	t_objs_list	*obj;

	plane = malloc(sizeof(t_plane));
	if (!plane || parse_plane(line, plane) == -1)
	{
		return (-1);
	}
	obj = create_plane(plane);
	if (!obj)
	{
		printf("Failed to create object\n");
		free(plane);
		return (-1);
	}
	add_member_to_obj_list(&window->objs, obj);
	return (1);
}

static int	handle_cylinder(const char *line, t_window *window)
{
	t_cylinder	*cylinder;
	t_objs_list	*obj;

	cylinder = malloc(sizeof(t_cylinder));
	if (!cylinder || parse_cylinder(line, cylinder) == -1)
		return (-1);
	obj = create_cylinder(cylinder);
	if (!obj)
	{
		printf("Failed to create object\n");
		free(cylinder);
		return (-1);
	}
	//free(cylinder);
	add_member_to_obj_list(&window->objs, obj);
	return (1);
}

int	parsing_start(char *line, t_window *window)
{
	if (ft_strncmp(line, "A", 1) == 0)
		return (parse_ambient(line, &window->ambient));
	else if (ft_strncmp(line, "C", 1) == 0)
		return (parse_camera(line, &window->camera));
	else if (ft_strncmp(line, "L", 1) == 0)
		return (parse_light(line, &window->light));
	else if (ft_strncmp(line, "sp", 2) == 0)
		return (handle_sphere(line, window));
	else if (ft_strncmp(line, "pl", 2) == 0)
		return (handle_plane(line, window));
	else if (ft_strncmp(line, "cy", 2) == 0)
		return (handle_cylinder(line, window));
	else
	{
		printf("Unknown element: %s\n", line);
		return (-1);
	}
	return (1);
}
