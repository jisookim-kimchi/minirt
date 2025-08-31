/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 20:24:04 by tfarkas           #+#    #+#             */
/*   Updated: 2025/08/31 20:37:48 by tfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_tools.h"
#include "../object/objects.h"

void	print_sphere_infos(const t_sphere *sphere)
{
	printf("\nThe sphere:\ncenter:\n");
	print_vec3(&sphere->center);
	printf("diamater: %f\n", sphere->diameter);
	print_color_float(&sphere->sphere_color);
}

void	print_plane_infos(const t_plane *plane)
{
	printf("\nThe plane:\npoint:\n");
	print_vec3(&plane->point);
	printf("unit_normal_vector:\n");
	print_vec3(&plane->unit_normal_vec);
	print_color_float(&plane->plane_color);
}

void	print_cylinder_infos(const t_cylinder *cylinder)
{
	printf("\nThe cylinder:\ncenter:\n");
	print_vec3(&cylinder->center);
	printf("axis:\n");
	print_vec3(&cylinder->axis);
	printf("diameter: %f\n", cylinder->diameter);
	printf("height: %f\n", cylinder->diameter);
	print_color_float(&cylinder->cylinder_color);
}
