/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:30:52 by tfarkas           #+#    #+#             */
/*   Updated: 2025/07/10 17:04:56 by tfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include "../math/mathheader.h"
# include "../math/vector_struct.h"
# include "../mlx_tools.h"

typedef enum e_obj_type
{
	PLANE,
	SPHERE,
	CYLINDER
}	t_obj_type;

/*
	The obj_fill enum define if the 3D objest is 
	empty inside or not
	SOLID = inside filled with the object material
	SHELL = inside NOT filled with the object material
*/
typedef enum e_obj_fill
{
	SOLID,
	SHELL
}	t_obj_fill

typedef struct s_objs_list
{
	t_obj_type	obj_type;
	void		*data;
	s_objs_list	*next;
}	t_objs_list;

/*
	The objects structures
*/
typedef struct s_plane
{
	t_vec3			unit_normal_vec;
	t_vec3			point;
	t_color_float	plane_color;
}	t_plane;

typedef struct s_sphere
{
	t_vec3			center;
	float			diameter;
	t_color_float	sphere_color;
	t_obj_fill		obj_fill;
}	t_sphere;

typedef struct s_cylinder
{
	t_vec3			axis;
	float			diamater;
	float			height;
	t_color_float	cylinder_color;
	t_obj_fill		obj_fill;
}	t_cylinder;

//2d_objects.c
t_objs_list	*create_plane(t_vec3 in_unit_normal_vec, 
	t_vec3 in_point, t_color_float in_plane_color);

#endif