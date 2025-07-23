/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:28:14 by tfarkas           #+#    #+#             */
/*   Updated: 2025/07/23 17:23:52 by jisokim2         ###   ########.fr       */
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
	sphere_diameter = 100.0f;
	center = vec3(0.0, 100.0, -500.0);
	sphere = create_sphere(center, sphere_diameter, sphere_color);
	
	//plane1
	t_objs_list		*plane1;
	t_vec3			plane_point1;
	t_vec3			unit_normal_vec1;
	t_color_float	plane_color1;

	color_float_set(&plane_color1, 0.0f, 0.0f, 1.0f); //blue
	plane_point1 = vec3(0.0, -10.0, -1000.0);
	unit_normal_vec1 = vec3_normalized((t_vec3){0.0, 1.0, 0.0}); //zx plane
	plane1 = create_plane(unit_normal_vec1, plane_point1, plane_color1);

	//plane2
	t_objs_list		*plane2;
	t_vec3			plane_point2;
	t_vec3			unit_normal_vec2;
	t_color_float	plane_color2;

	color_float_set(&plane_color2, 0.0f, 1.0f, 0.0f); //green
	plane_point2 = vec3(-10.0, 0.0, -700.0);
	unit_normal_vec2 = vec3(1.0, 0.0, 0.0);   //zy plane
	plane2 = create_plane(unit_normal_vec2, plane_point2, plane_color2);

	//cylinder
	t_objs_list		*cylinder;
	t_color_float	cylinder_color;
	float			diameter = 70.f;
	float			height = 200.f;
	t_vec3			cylinder_axis = vec3_normalized((t_vec3){1, 1, -1});
	t_vec3 			cylinder_center = {-30.0, 0.0, -500.0};

	color_float_set(&cylinder_color, 1.0f, 0.0f, 0.0f); //RED
	
	cylinder = create_cylinder(cylinder_axis, cylinder_center, diameter, height, cylinder_color);

	add_member_to_obj_list(&list, plane1);
	add_member_to_obj_list(&list, cylinder);
	add_member_to_obj_list(&list, sphere);
	add_member_to_obj_list(&list, plane2);

	return (list);
}
