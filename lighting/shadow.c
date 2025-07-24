# include "../lighting/lighting.h"

bool	is_shadow(t_objs_list *object, t_light *light, t_hit *hit)
{
	t_vec3	light_dir;
	double	light_len;

	light_dir = vec3_sub_vec3(light->light_position, hit->hit_point);
	light_len = vec3_length(light_dir);

	t_vec3	shadow_origin;
	t_vec3	shadow_dir;

	//if hit doubled then we need to adjust EPSILON value
	shadow_dir = vec3_multiply(vec3_normalized(light_dir), EPSILON * 50.f); //vector it has direction.
	shadow_origin = vec3_plus_vec3(hit->hit_point, shadow_dir);

	t_ray shadow_ray = ray(shadow_origin, shadow_dir);
	
	// hit->t_max = light_len;
	// hit->t_min = 0;
	t_hit temp_hit;
	temp_hit.t_max = light_len;
	temp_hit.t_min = 0;

	//if its hit;
	if (hit_world(&shadow_ray, &temp_hit, object))
	{
		t_color_float color = (t_color_float){0,0,0};
		hit->hit_color = color;
		return (true);
	}

	return (false);
}