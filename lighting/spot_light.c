# include "object/objects.h"
# include "lighting/lighting.h"

t_spot_light	init_spot_light(const t_light *light, t_vec3 direction, float distance, float angle, float intensity)
{
	t_spot_light spot_light;

	if (!light || distance <= 0 || angle <= 0 || intensity <= 0)
	{
		printf("worng input for point_light so we give DEFAULT point_light\n");
		spot_light.light.light_position = light->light_position;
		spot_light.light.light_ratio = light->light_ratio;
		spot_light.light.light_color = light->light_color;
		spot_light.angle = 60.f;
		spot_light.distance = 500.f;
		spot_light.direction = (t_vec3){0, -1, 0}; // default direction
		//we need to get ratio...
		spot_light.intensity = 2.f;
		return (spot_light);
	}
	spot_light.light.light_position = light->light_position;
	spot_light.light.light_ratio = light->light_ratio;
	spot_light.light.light_color = light->light_color;
	spot_light.distance = distance;
	spot_light.angle = angle;
	spot_light.intensity = intensity;
	return (spot_light);
}

//to set direction for spot light
void	set_spot_direction(t_spot_light *spot, t_vec3 direction)
{
	if (!spot)
	{
		printf("spot light is NULL\n");
	}
	spot->direction = vec3_normalized(direction);
}

/*
	check if the point is in the spot light cone
*/

bool	is_in_spot_cone(const t_spot_light *spot, t_vec3 point)
{
	if (!spot)
	{
		printf("spot light is NULL\n");
		return (false);
	}
	t_vec3 light_to_point = vec3_sub_vec3(point, spot->light.light_position);
	double distance_to_light = vec3_length(light_to_point);
	if (distance_to_light > spot->distance)
		return (false);
	
	t_vec3 normalized_direction = vec3_normalized(spot->direction);
	double angle_cosine = cos(deg2rad(spot->angle) / 2);
	double point_cosine = vec3_dot(vec3_normalized(light_to_point), normalized_direction);

	if (point_cosine < angle_cosine)
		return (false);
	return (true);
}

float	spot_light_intensity_at(const t_spot_light *spot, t_vec3 point, t_vec3 normal)
{
	if (!spot || !is_in_spot_cone(spot, point))
		return (0.0f);
	
	t_vec3 light_to_point = vec3_sub_vec3(point, spot->light.light_position);
	double distance_to_light = vec3_length(light_to_point);
	if (distance_to_light > spot->distance)
		return (0.0f);

	t_vec3 normalized_direction = vec3_normalized(spot->direction);
	double angle_cosine = cos(deg2rad(spot->angle) / 2);
	double point_cosine = vec3_dot(vec3_normalized(light_to_point), normalized_direction);

	if (point_cosine < angle_cosine)
		return (0.0f);

	float intensity = spot->intensity * spot->light.light_ratio;
	return (intensity);
}