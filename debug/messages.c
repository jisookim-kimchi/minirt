/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:14:47 by tfarkas           #+#    #+#             */
/*   Updated: 2025/08/31 20:44:13 by tfarkas          ###   ########.fr       */
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
	printf("x:\t%f\ny:\t%f\nz:\t%f\n", vec3->x, vec3->y, vec3->z);
}

void	print_color_float(const t_color_float *float_color)
{
	printf("The float color values:\n"
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
