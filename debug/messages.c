/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:14:47 by tfarkas           #+#    #+#             */
/*   Updated: 2025/08/30 18:09:17 by jisokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_tools.h"
#include "../object/objects.h"

void	print_vec3(const t_vec3 *vec3)
{
	if (!vec3)
	{
		printf("%sThe vector point is NULL%s\n", RED, DEFAULT);
		return ;
	}
	printf("The vector has the following values\n"
		"x:\t%f\ny:\t%f\nz:\t%f\n", vec3->x, vec3->y, vec3->z);
}

void	print_color_float(const t_color_float *float_color)
{
	printf("\nThe float color values:\n"
		"red: %f\tgreen: %f\tblue: %f\n",
		float_color->red, float_color->green, float_color->blue);
}

void	print_color_compare(const t_color_float *float_color1,
	const t_color_float *float_color2)
{
	printf("%sThe first color values:", BLUE);
	print_color_float(float_color1);
	printf("%sThe second color values:", CYAN);
	print_color_float(float_color2);
	printf("%s", DEFAULT);
}

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
