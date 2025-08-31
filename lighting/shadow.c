/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 17:25:59 by tfarkas           #+#    #+#             */
/*   Updated: 2025/08/31 21:29:53 by tfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lighting/lighting.h"

static bool	shadow_hit_world(t_ray *ray, t_hit *record, t_objs_list *objects)
{
	bool		found_hit;
	t_objs_list	*loop_objects;
	t_hit		temp;

	if (!ray || !record || !objects)
	{
		printf("Error : NULL PTR in hit_world\n");
		return (false);
	}
	temp.t_max = record->t_max;
	found_hit = false;
	loop_objects = objects;
	while (loop_objects)
	{
		// printf(YELLOW"loop_objects: %p\n"DEFAULT, loop_objects->data);
		// printf(BLUE"record->object.data: %p\n"DEFAULT, record->object.data);
		
		if ((loop_objects->data != record->object.data)
			&& ray_intersect(loop_objects, ray, &temp))
		{
			printf(BLUE"record->object.data: %p\n"DEFAULT, record->object.data);
			found_hit = true;
			temp.t_max = temp.t;
			*record = temp;
			record->object.obj_type = temp.object.obj_type;
			record->object.data = temp.object.data;
		}
		loop_objects = loop_objects->next;
	}
	// printf(CYAN"shadow hit world found hit: %d\n"DEFAULT, found_hit);
	return (found_hit);
}

/*
	Maybe in the if statement part need to fresh the hit->object data

	if (hit_world(shadow_ray, &temp_hit, object))
	{
		// printf("is_shadow obj_type : %d\n", temp_hit.object.obj_type);
		// hit->object = temp_hit.object;
		// hit->object.data = temp_hit.object.data;
		// hit->object.obj_type = temp_hit.object.obj_type;
		return (true);
	}
*/
static bool	shadow_object_loop(t_objs_list *object,
	t_hit *hit, t_ray *shadow_ray)
{
	t_hit	temp_hit;
	double	shadow_len;

	shadow_len = vec3_length(shadow_ray->dir);
	temp_hit.t_max = shadow_len;
	temp_hit.t_min = EPSILON;
	temp_hit.object = hit->object;
	temp_hit.object.data = hit->object.data;
	temp_hit.object.obj_type = hit->object.obj_type;
	// printf(CYAN"shadow loop before hit world\n"DEFAULT);
	if (shadow_hit_world(shadow_ray, &temp_hit, object))
	{
		hit->object = temp_hit.object;
		hit->object.data = temp_hit.object.data;
		hit->object.obj_type = temp_hit.object.obj_type;
		return (true);
	}
	// printf(MAGENTA"shadow loop after hit world\n"DEFAULT);
	return (false);
}

/*
	object : all objects.

	If hit doubled then we need to adjust EPSILON value
	If the hit point is on the surface then we need to add a small offset
		shadow_offset = vec3_multiply((shadow_dir), EPSILON * 50.f);

	debug printf line:
		if (vec3_dot(vec3_sub_vec3(shadow_origin, hit->hit_point), 
			hit->normal) <= -0.8)
		printf("error\n");
*/
bool	is_shadow(t_objs_list *object, t_light *light, t_hit *hit)
{
	t_vec3	shadow_dir;
	t_vec3	shadow_origin;
	t_vec3	shadow_offset;
	t_ray	shadow_ray;

	if (light->is_light == false)
		return (false);
	shadow_dir = vec3_sub_vec3(light->light_position, hit->hit_point);
	shadow_offset = vec3_multiply(hit->normal, EPSILON);
	shadow_origin = vec3_plus_vec3(hit->hit_point, shadow_offset);
	shadow_ray = create_ray(shadow_origin, shadow_dir);
	return (shadow_object_loop(object, hit, &shadow_ray));
}
