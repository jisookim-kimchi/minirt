/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:30:52 by tfarkas           #+#    #+#             */
/*   Updated: 2025/08/23 15:23:45 by jisokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include "../Precompiled/loadresource.h"
//# include "../mlx_tools.h"

typedef struct s_objs_list	t_objs_list;
typedef struct s_objs_list	t_hittable_objs;

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
}	t_obj_fill;

typedef struct s_objs_list
{
	t_obj_type			obj_type;
	bool				has_checkerboard;
	void				*data;
	struct s_objs_list	*next;
}	t_objs_list;

/*
	The objects structures
*/

typedef struct s_material 
{
    mlx_texture_t* diffuse;
    mlx_texture_t* normal;
    mlx_texture_t* bump;
} t_material;

typedef struct s_uv
{
	double	u;
	double	v;
	float	tile_scale;
} t_uv;

typedef struct s_plane
{
	t_material		material;
	t_uv			uv;
	t_vec3			unit_normal_vec;
	t_vec3			point;
	t_color_float	plane_color;
}	t_plane;

typedef struct s_sphere
{
	t_material		material;
	t_uv			uv;
	t_vec3			center;
	float			diameter;
	t_color_float	sphere_color;
	t_obj_fill		obj_fill;
}	t_sphere;

typedef struct s_cylinder
{
	t_material		material;
	t_uv			cap_uv;
	t_uv			side_uv;
	bool			is_side_hit;
	bool			is_cap_hit;
	t_vec3			axis;
	float			diameter;
	float			height;
	t_color_float	cylinder_color;
	t_obj_fill		obj_fill;
	t_vec3			center;
}	t_cylinder;

/*
	Maybe it is good to store the color, front face, and the object
	bool			front_face;
	
*/
typedef struct s_hit
{
	float			t;
	float			t_min;
	float			t_max;
	t_vec3			hit_point;
	t_vec3			normal;
	t_objs_list		object;
	t_color_float	hit_color;
}	t_hit;

//2d_objects.c
t_objs_list	*create_plane(t_vec3 in_unit_normal_vec,
				t_vec3 in_point, t_color_float in_plane_color);

//3d_objects.c
t_objs_list	*create_sphere(t_vec3 in_center,
				float in_diameter, t_color_float in_sphere_color);
t_objs_list	*create_cylinder(t_vec3 in_axis, t_vec3 center,
				float in_diameter, float in_height,
				t_color_float in_cylinder_color);

//object_list.c
void			add_member_to_obj_list(t_objs_list **list, t_objs_list *new_member);
void			free_objs_list(t_objs_list **list);
bool			ray_intersect(t_objs_list *obj, t_ray *ray, t_hit *hit);
bool			hit_world(t_ray *ray, t_hit *record, t_objs_list *objects);
void			set_ray_interval(t_hit *hit, float set_t_min, float set_t_max);
void			print_objs(t_objs_list *obj);
t_hittable_objs	*get_hittable_list(t_objs_list *obj, t_ray *ray, t_hit *hit);

//object_intersect.c
void		set_ray_opposite_normal(t_ray *ray, t_hit *hit, t_vec3 normal);
bool		hit_sphere(t_sphere *sphere, t_ray *ray, t_hit *hit);
bool		hit_plane(t_plane *plane, t_ray *ray, t_hit *hit);

bool      	hit_cylinder( t_cylinder *cylinder, t_ray *ray, t_hit *hit);
bool		hit_cylinder_cap(t_cylinder *cylinder, t_vec3 cap_center, t_ray *ray, t_hit *hit, t_vec3 cap_normal);
bool		hit_cylinder_side(t_cylinder *cylinder, t_ray *ray, t_hit *hit);

void		calculate_plane_uv(t_plane* plane, t_vec3 hit_point);
void		calculate_sphere_uv(t_sphere *sphere, t_vec3 hit_point);
//check_interval.c
float		clamp_calculation(float input_value, float min, float max);
bool		check_value_in_range(float input_value, float min, float max);
double		double_clamp_calculation(double input_value, double min, double max);
#endif