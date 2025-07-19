/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:28:14 by tfarkas           #+#    #+#             */
/*   Updated: 2025/07/19 16:57:12 by jisokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../object/objects.h"
#include "../debug/debug.h"

/*
	This init_objs_list function create some object to start test the program.
	Later it will be change to get the informtion from the rt file.
*/
t_objs_list	*init_objs_list(void)
{
	//sphere
	t_objs_list		*list;
	t_objs_list		*sphere;
	t_color_float	sphere_color;
	t_vec3			center;
	float			sphere_diameter;

	list = NULL;
	ft_putendl_fd("In init_objs_list start", 2);
	sphere_color.red = 1.0f;
	sphere_color.green = 0.0f;
	sphere_color.blue = 0.0f;
	sphere_diameter = 100.5f;
	center = vec3(0.0, 0.0, -500.0);
	sphere = create_sphere(center, sphere_diameter, sphere_color);
	
	//plane
	t_objs_list		*plane;
	t_vec3			plane_point;
	t_vec3			unit_normal_vec;
	t_color_float	plane_color;

	color_float_set(&plane_color, 0.0f, 0.0f, 1.0f);
	plane_point = vec3(10.0, 10.0, -1000.0);
	unit_normal_vec = vec3(0.0, 1.0, 0.0);
	plane = create_plane(unit_normal_vec, plane_point, plane_color);
	// t_plane *test = (t_plane *)(plane->data);
	// printf("test %f , %f, %f\n", test->plane_color.blue, test->plane_color.green, test->plane_color.red);
	// pointer_address_message(plane);
	// object_adress(plane);

	add_member_to_obj_list(&list, plane);
	add_member_to_obj_list(&list, sphere);

	return (list);
}
