#include "loadresource.h"
#include "lighting.h"

int	parse_ambient(char *line, t_ambient *ambient)
{
	char			**tokens;
	t_color_float	color;
	float			ratio;

	tokens = ft_split(line);
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
	{
		//free tokens
		return (-1);
	}
	//parse color
	paras_color(tokens[2], ambient.ambient_color.red, ambient.ambient_color.green, ambient.ambient_color.blue);
	ambient.ambient_ratio = ratio;
	return (1);
}

//todo 
int	parse_camera(char *line, t_camera camera)
{
	char			**tokens;
	t_vec3			pos;
	t_vec3			orientation;
	float			fov;

	tokens = ft_split(line);
	if (!tokens)
		return (-1);

	//check param num for ambinet it must be 3.
	if (count_array_elem(tokens) != 4)
	{
		//free tokens?
		return (-1);
	}
	camera.transform_comp.pos.x = t_vec
	

}