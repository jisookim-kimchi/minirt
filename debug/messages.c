/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:14:47 by tfarkas           #+#    #+#             */
/*   Updated: 2025/07/16 14:35:40 by tfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_tools.h"

void	print_vec3(const t_vec3 * vec3)
{
	if (!vec3)
	{
		printf("%sThe vector point is NULL%s\n", RED, DEFAULT);
		return ;
	}
	printf("The vector has the following values\n"
		"x:\t%f\ny:\t%f\nz:\t%f\n", vec3->x, vec3->y, vec3->z);
}
