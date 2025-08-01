#include "parser.h"

int	parse_ambient(char *line, t_ambient *ambient)
{
	char			**tokens;
	float			ratio;

	tokens = ft_split(line, ' ');
	if (!tokens)
		return (-1);

	//check param num for ambinet it must be 3.
	if (count_array_elem(tokens) != 3)
	{
		//free tokens?
		return (-1);
	}
	//change to float
	ratio = ft_atof(tokens[1]);
	if (ratio < 0.0 || ratio > 1.0)
	{
		//free tokens
		return (-1);
	}
	//parse color
	parse_color(tokens[2], &ambient->ambient_color.red, &ambient->ambient_color.green, &ambient->ambient_color.blue);
	//printf("ambient_color %p\n", &ambient->ambient_color);
	ambient->ambient_ratio = ratio;
	return (1);
}


int	parse_camera(char *line, t_camera *camera)
{
	char			**tokens;
	float			fov;
	tokens = ft_split(line, ' ');
	if (!tokens)
	{
		//printf("camera1\n");
		return (-1);
	}
	//check param num for ambinet it must be 3.
	if (count_array_elem(tokens) != 4)
	{
		//printf("camera 1\n");
		//free tokens?
		return (-1);
	}
	parse_vec3(tokens[1], &camera->transform_comp.transform->position.x, &camera->transform_comp.transform->position.y, &camera->transform_comp.transform->position.z);
	// printf("token1 done \n");
	// printf("camera position[%p]: %f, %f, %f\n", &camera->transform_comp.transform->position, camera->transform_comp.transform->position.x, camera->transform_comp.transform->position.y, camera->transform_comp.transform->position.z);
	parse_vec3(tokens[2], &camera->transform_comp.forward.x, &camera->transform_comp.forward.y, &camera->transform_comp.forward.z);
	if ((camera->transform_comp.forward.x > 1 || camera->transform_comp.forward.x < -1) || (camera->transform_comp.forward.y > 1 || camera->transform_comp.forward.y < -1) || (camera->transform_comp.forward.z > 1 || camera->transform_comp.forward.z < -1))
	{
		//printf("camera 2\n");
		//free tokens?
		return (-1);
	}
	fov = ft_atof(tokens[3]);
	if (fov < 0 || fov > 180)
	{
		//printf("camera 3\n");
		//free tokens? garbagecollector?
		return (-1);
	}
	camera->transform_comp.forward = vec3_normalized(camera->transform_comp.forward);
	if (fabs(vec3_dot(camera->transform_comp.forward, vec3(0.0, 1.0, 0.0))) > 0.999f)
		camera->transform_comp.right = vec3_cross(camera->transform_comp.forward ,(t_vec3){0, 0, 1});
	else
		camera->transform_comp.right = vec3_cross(camera->transform_comp.forward ,(t_vec3){0, 1, 0});
	camera->transform_comp.up = vec3_cross(camera->transform_comp.right, camera->transform_comp.forward);
	camera->fov = fov;
	return (1);
}

int	parse_light(char *line, t_light *light)
{
	//t_vec3	pos;
	char	**tokens;
	
	tokens = ft_split(line, ' ');
	if (!tokens)
		return (-1);
	if (count_array_elem(tokens) != 4)
	{
		//free tokens?
		return (-1);
	}
	parse_vec3(tokens[1], &light->light_position.x, &light->light_position.y, &light->light_position.z);
	light->light_ratio = ft_atof(tokens[2]);
	if (!check_value_in_range(light->light_ratio, 0.0, 1.0))
		return (-1);
	parse_color(tokens[3], &light->light_color.red, &light->light_color.green, &light->light_color.blue);
	light->is_light = true;
	return (1);
}