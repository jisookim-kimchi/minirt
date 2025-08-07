/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 14:17:59 by jisokim2          #+#    #+#             */
/*   Updated: 2025/08/07 17:21:07 by jisokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
/*
	todo change name
	check each line and validate weather its requiered params
*/
int	parsing_start(char *line, t_window *window)
{
	t_objs_list		*list;
	if (ft_strncmp(line, "A", 1) == 0)
	{
		if (parse_ambient(line, &window->ambient) == -1)
		{
			//return ? or free all and exit(1);
			return (-1);
		}
	}
	else if (ft_strncmp(line, "C", 1) == 0)
	{
		if (parse_camera(line, &window->camera) == -1)
		{
			//return ? or free all and exit(1);
			return (-1);
		}
	}
	else if (ft_strncmp(line, "L", 1) == 0)
	{
		if (parse_light(line, &window->light) == -1)
		{
			//return ? or free all and exit(1);
			return (-1);
		}
	}
	else if (ft_strncmp(line, "sp", 2) == 0)
	{
		printf(CYAN"1\n");
		t_sphere *sphere = malloc(sizeof(t_sphere));
		if (!sphere || parse_sphere(line, sphere) == -1)
		{
			//return ? or free all and exit(1);
			return (-1);
		}
		t_objs_list *obj = create_sphere(sphere->center, sphere->diameter, sphere->sphere_color);
		// printf("sphere center %f, %f, %f\n", sphere->center.x, sphere->center.y, sphere->center.z);
		// printf("sphere diameter %f,\n", sphere->diameter);
		// printf("sphere color %f, %f, %f\n"DEFAULT, sphere->sphere_color.red, sphere->sphere_color.green, sphere->sphere_color.blue);
		add_member_to_obj_list(&list, obj);
	}
	else if (ft_strncmp(line, "pl", 2) == 0)
	{
		t_plane *plane = malloc(sizeof(t_plane));
		if (!plane || parse_plane(line, plane) == -1)
		{
			//return ? or free all and exit(1);
			return (-1);
		}
		// if (parse_plane(line, &window->objs->plane) == -1)
		// {
		// 	//return ? or free all and exit(1);
		// 	return (-1);
		// }
		t_objs_list *obj = create_plane(plane->unit_normal_vec, plane->point, plane->plane_color);
		add_member_to_obj_list(&list, obj);
	}
	
	else if (ft_strncmp(line, "cy", 2) == 0)
	{
		
		t_cylinder *cylinder = malloc(sizeof(t_cylinder));
		if (!cylinder || parse_cylinder(line, cylinder) == -1)
		{
			//return ? or free all and exit(1);
			return (-1);
		}
		// if (parse_cylinder(line, &window->objs->cylinder) == -1)
		// {
		// 	//return ? or free all and exit(1);
		// 	return (-1);
		// }
		t_objs_list *obj = create_cylinder(cylinder->axis, cylinder->center, cylinder->diameter, cylinder->height, cylinder->cylinder_color);
		add_member_to_obj_list(&list, obj);
	}
	else
	{
		printf("Unknown element: %s\n", line);
		return (-1);
	}
	// else
	// 	return (-1);
	return (1);
}

/*
	check if it has minimum components for rendering.
*/
// int	has_minimum_components()
// {
		
// }
