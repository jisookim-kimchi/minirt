# include "../lighting/lighting.h"

/*
	object : all objects.

*/
bool	is_shadow(t_objs_list *object, t_light *light, t_hit *hit)
{
	if (light->is_light == false)
	{
		return false;
	}
	t_vec3	shadow_dir;
	double	shadow_len;

	shadow_dir = vec3_sub_vec3(light->light_position, hit->hit_point);
	shadow_len = vec3_length(shadow_dir);

	t_vec3	shadow_origin;
	t_vec3	shadow_offset;

	//if hit doubled then we need to adjust EPSILON value
	//if the hit point is on the surface then we need to add a small offset
	shadow_offset = vec3_multiply(hit->normal, EPSILON);
	//shadow_offset = vec3_multiply((shadow_dir), EPSILON * 50.f); //vector it has direction.
	shadow_origin = vec3_plus_vec3(hit->hit_point, shadow_offset);

	t_ray shadow_ray = create_ray(shadow_origin, shadow_dir);

	// if (vec3_dot(vec3_sub_vec3(shadow_origin, hit->hit_point), hit->normal) <= -0.8)
	// 	printf("error\n");

	t_hit temp_hit;
	temp_hit.t_max = shadow_len;
	// temp_hit.t_min = 0;
	temp_hit.t_min = EPSILON; //to avoid self hit.
	temp_hit.object = hit->object;
	temp_hit.object.data = hit->object.data;
	temp_hit.object.obj_type = hit->object.obj_type;
	//if its hit;
	if (hit_world(&shadow_ray, &temp_hit, object))
	{
		// if (temp_hit.object.obj_type == PLANE)
		// 	printf("PLANE\n");
		// if (temp_hit.object.obj_type == SPHERE)
		// 	printf("SPHERE\n");
		// if (temp_hit.object.obj_type == CYLINDER)
		// 	printf("CYLINDER\n");

		//todo no meaning.
		// t_color_float color = (t_color_float){0,0,0};
		// temp_hit.hit_color = color;
		return (true);
	}

	return (false);
}
