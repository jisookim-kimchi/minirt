/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_float_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 17:32:13 by jisokim2          #+#    #+#             */
/*   Updated: 2025/08/30 17:44:52 by jisokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathheader.h"

t_color3	color_float_to_col3(t_color_float input)
{
	t_color3	col3;

	col3.x = (double)input.red;
	col3.y = (double)input.green;
	col3.z = (double)input.blue;
	return (col3);
}

t_color_float	color_col3_to_float(t_color3 input)
{
	t_color_float	col_float;

	col_float.red = (float)input.x;
	col_float.green = (float)input.y;
	col_float.blue = (float)input.z;
	return (col_float);
}
