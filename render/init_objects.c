/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:28:14 by tfarkas           #+#    #+#             */
/*   Updated: 2025/07/15 13:42:04 by tfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../object/objects.h"

/*
	This init_objs_list function create some object to start test the program.
	Later it will be change to get the informtion from the rt file.
*/
t_objs_list	*init_objs_list(void)
{
	t_objs_list		*list;
	t_color_float	sphere_color;
	t_vec3			center;
	float			sphere_diameter;

	sphere_color.red = 1.0f;
	sphere_color.green = 0.0f;
	sphere_color.blue = 0.0f;
	create_sphere()
	
	return (list);
}