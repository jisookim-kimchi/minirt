#include "loadresource.h"
#include "lighting.h"

int	count_array_elem(char **tokens)
{
	int	i;

	i = 0;
	while([i])
	{
		i++;
	}
	return (i);
}

//todo handle floating number.
float	ft_atof(char *str)
{
	float	num;
	int		sign;

	sign = 1;
	num = 0.0;
	
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str >= '0' || *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	
	if (*str == '.')
	{
		str++;
	}

}

int	check_ambient(char *line, t_ambient ambient)
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

	//parse color
	color = paras_color(tokens[2]);
}