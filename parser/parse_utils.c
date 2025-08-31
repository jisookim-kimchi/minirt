/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 10:04:00 by jisokim2          #+#    #+#             */
/*   Updated: 2025/08/31 19:58:39 by tfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

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

// int	is_valid_input(char *token)
// {
// 	int		i;
// 	int		seen;

// 	i = 0;
// 	seen = 0;
// 	if (!ft_isdigit(token[0]) && !(token[0] == '-'))
// 		return (-1);
// 	if ((token[0] == '-' && token[1] == '.') || (token[0] == '.'))
// 		return (-1);
// 	if (token[0] == '-')
// 		i++;
// 	while (token[i])
// 	{
// 		if (token[i] == '.')
// 			seen++;
// 		if (seen > 1 || !ft_isdigit(token[i]))
// 		{
// 			printf(YELLOW"token[%d]: %c\n"DEFAULT, i, token[i]);
// 			return (-1);
// 		}
// 		i++;
// 	}
// 	return (1);
// }

int	is_valid_input(char *token)
{
	int		i;

	i = 0;
	if (ft_strchr(token, '.') != ft_strrchr(token, '.'))
		return (-1);
	if (!ft_isdigit(token[0]) && !(token[0] == '-'))
		return (-1);
	if ((token[0] == '-' && token[1] == '.') || (token[0] == '.'))
		return (-1);
	if (token[0] == '-')
		i++;
	while (token[i])
	{
		if (!ft_isdigit(token[i]) && token[i] != '.')
		{
			printf(YELLOW"token[%d]: %c\n"DEFAULT, i, token[i]);
			return (-1);
		}
		i++;
	}
	return (1);
}

int	parse_vec3(char *token, double *x, double *y, double *z)
{
	char	**temp;
	int		i;

	temp = ft_split(token, ',');
	i = 0;
	if (!temp || count_array_elem(temp) != 3)
	{
		return (-1);
	}
	while (i < 3)
	{
		if (is_valid_input(temp[i]) < 0)
		{
			printf(RED"Error parse_vec3(): %s\n"DEFAULT, temp[i]);
			free_splited_str(temp);
			return (-1);
		}
		i++;
	}
	*x = ft_atof(temp[0]);
	*y = ft_atof(temp[1]);
	*z = ft_atof(temp[2]);
	free_splited_str(temp);
	return (1);
}
