/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 10:04:00 by jisokim2          #+#    #+#             */
/*   Updated: 2025/08/29 12:39:26 by jisokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*ft_strtok(char *str, const char c)
{
	static char	*input;
	char		*start;
	int			i;

	i = 0;
	if (str)
		input = str;
	if (!input || !*input)
		return (NULL);
	start = input;
	while (input[i] && input[i] != c && input[i] != '\n')
		i++;
	if (input[i])
	{
		input[i] = '\0';
		input = &input[i + 1];
	}
	else
		input = NULL;
	return (start);
}

int	count_array_elem(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		i++;
	}
	return (i);
}

static int	parse_single_color(char *token, float *color)
{
	if (!token || is_digit(token) == -1)
		return (-1);
	*color = ft_atof(token);
	if (!check_value_in_range(*color, 0.0, 255.0))
		return (-1);
	*color /= 255.f;
	return (1);
}

int	parse_color(char *token, float *red, float *green, float *blue)
{
	char	*temp;

	if (ft_strchr(token, '.'))
	{
		printf("error parse_color\n");
		return (-1);
	}
	temp = ft_strtok(token, ',');
	if (parse_single_color(temp, red) == -1)
		return (-1);
	temp = ft_strtok(NULL, ',');
	if (parse_single_color(temp, green) == -1)
		return (-1);
	temp = ft_strtok(NULL, ',');
	if (parse_single_color(temp, blue) == -1)
		return (-1);
	return (1);
}

int	parse_vec3(char *token, double *x, double *y, double *z)
{
	char	**temp;

	temp = ft_split(token, ',');
	if (!temp || count_array_elem(temp) != 3)
	{
		return (-1);
	}
	*x = ft_atof(temp[0]);
	*y = ft_atof(temp[1]);
	*z = ft_atof(temp[2]);
	free_splited_str(temp);
	return (1);
}
