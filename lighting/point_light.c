# include "object/objects.h"
# include "lighting/lighting.h"

t_point_light	init_point_light(const t_light *light, float distance, float angle, float intensity)
{
	t_point_light point_light;

	if (!light || distance <= 0 || angle <= 0 || intensity <= 0)
	{
		printf("worng input for point_light so we give DEFAULT point_light\n");
		point_light.light.light_position = light->light_position;
		point_light.light.light_ratio = light->light_ratio;
		point_light.light.light_color = light->light_color;
		point_light.angle = 60.f;
		point_light.distance = 500.f;
		//we need to get ratio...
		point_light.intensity = 2.f;
		return (point_light);
	}
	point_light.light.light_position = light->light_position;
	point_light.light.light_ratio = light->light_ratio;
	point_light.light.light_color = light->light_color;
	point_light.distance = distance;
	point_light.angle = angle;
	point_light.intensity = intensity;
	return (point_light);
}

