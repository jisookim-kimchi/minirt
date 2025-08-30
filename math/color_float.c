/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 17:23:51 by jisokim2          #+#    #+#             */
/*   Updated: 2025/08/30 17:43:32 by jisokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathheader.h"

t_color_float	color_float_add(t_color_float color1, t_color_float color2)
{
	t_color_float	result;

	result.red = color1.red + color2.red;
	result.green = color1.green + color2.green;
	result.blue = color1.blue + color2.blue;
	return (result);
}

t_color_float	color_float_multiply(t_color_float color, double t)
{
	t_color_float	result;

	result.red = color.red * t;
	result.green = color.green * t;
	result.blue = color.blue * t;
	return (result);
}

t_color_float	color_float_divide(t_color_float color, double t)
{
	t_color_float	result;

	result.red = color.red / t;
	result.green = color.green / t;
	result.blue = color.blue / t;
	return (result);
}

t_color_float	color_float_multiply_vec3(t_color_float a, t_color_float b)
{
	t_color_float	result;

	result.red = a.red * b.red;
	result.green = a.green * b.green;
	result.blue = a.blue * b.blue;
	return (result);
}

void	color_float_set(t_color_float *color3,
	float in_red, float in_green, float in_blue)
{
	color3->red = in_red;
	color3->green = in_green;
	color3->blue = in_blue;
}
