/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 14:17:59 by jisokim2          #+#    #+#             */
/*   Updated: 2025/07/26 14:56:03 by jisokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "loadresource.h"

/*
	todo change name
	check each line and validate weather its requiered params
*/
int	validate_params(char *line)
{
	if (ft_strncmp(line, "A", 1) == 0)
		printf("Ambient\n");
	else if (ft_strncmp(line, "C", 1) == 0)
		printf("Camera\n");
	else if (ft_strncmp(line, "L", 1) == 0)
		printf("Light\n");
	else if (ft_strncmp(line, "sp", 2) == 0)
		printf("Sphere\n");
	else if (ft_strncmp(line, "pl", 2) == 0)
		printf("Plane\n");
	else if (ft_strncmp(line, "cy", 2) == 0)
		printf("Cylinder\n");
	else
		return (-1);
}

/*
	check if it has minimum components for rendering.
*/
// int	has_minimum_components()
// {
		
// }
