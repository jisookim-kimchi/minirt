/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OBJ_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 17:04:26 by jisokim2          #+#    #+#             */
/*   Updated: 2025/08/29 12:31:25 by jisokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	parse_plane(const char *line, t_plane *plane)
{
	char	**tokens;

	tokens = ft_split(line, ' ');
	if (!tokens || count_array_elem(tokens) != 4)
		return (-1);
	parse_vec3(tokens[1], &plane->point.x, &plane->point.y, &plane->point.z);
	parse_vec3(tokens[2], &plane->unit_normal_vec.x,
		&plane->unit_normal_vec.y, &plane->unit_normal_vec.z);
	plane->unit_normal_vec = vec3_normalized(plane->unit_normal_vec);
	parse_color(tokens[3], &plane->plane_color.red,
		&plane->plane_color.green, &plane->plane_color.blue);
	free_splited_str(tokens);
	return (1);
}

int	parse_sphere(const char *line, t_sphere *sphere)
{
	char	**tokens;

	tokens = ft_split(line, ' ');
	if (!tokens || count_array_elem(tokens) != 4)
		return (-1);
	parse_vec3(tokens[1], &sphere->center.x,
		&sphere->center.y, &sphere->center.z);
	sphere->diameter = ft_atof(tokens[2]);
	if (sphere->diameter < EPSILON)
	{
		free_splited_str(tokens);
		ft_putstr_fd(RED "Sphere Diameter is Negative\n" DEFAULT, 1);
		return (-1);
	}
	parse_color(tokens[3], &sphere->sphere_color.red,
		&sphere->sphere_color.green, &sphere->sphere_color.blue);
	free_splited_str(tokens);
	return (1);
}

int	parse_cylinder(const char *line, t_cylinder *cylinder)
{
	char	**tokens;

	tokens = ft_split(line, ' ');
	if (!tokens || count_array_elem(tokens) != 6)
		return (-1);
	parse_vec3(tokens[1], &cylinder->center.x,
		&cylinder->center.y, &cylinder->center.z);
	parse_vec3(tokens[2], &cylinder->axis.x,
		&cylinder->axis.y, &cylinder->axis.z);
	cylinder->axis = vec3_normalized(cylinder->axis);
	cylinder->diameter = ft_atof(tokens[3]);
	cylinder->height = ft_atof(tokens[4]);
	parse_color(tokens[5], &cylinder->cylinder_color.red,
		&cylinder->cylinder_color.green, &cylinder->cylinder_color.blue);
	free_splited_str(tokens);
	return (1);
}
