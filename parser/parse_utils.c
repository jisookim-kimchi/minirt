/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 10:04:00 by jisokim2          #+#    #+#             */
/*   Updated: 2025/08/28 17:00:20 by jisokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
	255,255,255
*/
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

/* 	//todo
	integer or float?
	because we getting integer value from file...
	need to discuss about it.

	// 255,255,255
*/

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

// we can get also float value...
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

void	free_splited_str(char **to_free)
{
	int	i;

	i = 0;
	while (to_free[i])
	{
		free (to_free[i]);
		to_free[i] = NULL;
		i++;
	}
	free (to_free);
	to_free = NULL;
}

int	is_digit(const char *token)
{
	int	i;

	i = 0;
	while (token[i])
	{
		if (ft_isdigit(token[i]))
		{
			i++;
		}
		else
		{
			return (-1);
		}
	}
	return (1);
}
/*
	float	ft_atof(char *str, bool *flag_float) 
	//todo to check if we need that declare 
*/

static void	jmp_whitespace_and_sign(const char **str, int *sign)
{
	while (**str == ' ' || (**str >= 9 && **str <= 13))
		(*str)++;
	if (**str == '-')
	{
		*sign = -1;
		(*str)++;
	}
}

static double	convert_to_integer(const char **str)
{
	double	num;

	num = 0.0;
	while (**str >= '0' && **str <= '9')
	{
		num = num * 10 + (**str - '0');
		(*str)++;
	}
	return (num);
}

static double	convert_to_frac(const char **str)
{
	double	div;
	double	frac;
	float	temp;

	temp = 0.f;
	div = 1.0;
	frac = 0.0;
	if (**str == '.')
	{
		(*str)++;
		while (**str >= '0' && **str <= '9')
		{
			temp = (**str - '0');
			div *= 10.0;
			frac += temp / div;
			(*str)++;
		}
	}
	return (frac);
}

float	ft_atof(const char *str)
{
	double		num;
	int			sign;
	double		frac;

	frac = 0.0;
	sign = 1;
	num = 0.0;
	if (!str)
		return (-1.0);
	jmp_whitespace_and_sign(&str, &sign);
	num = convert_to_integer(&str);
	frac = convert_to_frac(&str);
	return ((frac + num) * sign);
}
