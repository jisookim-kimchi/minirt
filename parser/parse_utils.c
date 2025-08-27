/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 10:04:00 by jisokim2          #+#    #+#             */
/*   Updated: 2025/08/11 15:41:42 by jisokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
	255,255,255
*/
char *ft_strtok(char *str, const char c)
{
	static char *input;
	char		*start;
	int			i;

	i = 0;
	if (str)
		input = str;
	if (!input || !*input)
		return (NULL);
	start = input;
	while(input[i] && input[i] != c && input[i] != '\n')
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
	while(tokens[i])
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

int	parse_color(char *token, float *red, float *green, float *blue)
{
	char			*temp;
	
	if (ft_strchr(token, '.'))
	{
		printf("error parse_color\n");
		return (-1);
	}
	
	temp = ft_strtok(token, ',');
	if (!temp)
		return (-1);
	if (is_digit(temp) == -1)
		return (-1);
	*red = ft_atof(temp);
	if (!check_value_in_range(*red, 0.0, 255.0))
		return (-1);
	*red /= 255.f;
	
	temp = ft_strtok(NULL, ',');
	if (!temp)
		return (-1);
	if (is_digit(temp) == -1)
	 	return (-1);
	*green = ft_atof(temp);
	if (!check_value_in_range(*green, 0.0, 255.0))
		return (-1);
	*green /= 255.f;
	
	temp = ft_strtok(NULL, ',');
	if (!temp)
	{
		return (-1);
	}
	if (is_digit(temp) == -1)
	{
		return (-1);
	}
	*blue = ft_atof(temp);
	if (!check_value_in_range(*blue, 0.0, 255.0))
	{
		return (-1);
	}
	*blue /= 255.f;
	return (1);
}

// we can get also float value...
int	parse_vec3(char *token, double *x, double *y, double *z)
{
	// char			*temp;

	// temp = ft_strtok(token, ',');

	// if (!temp)
	// 	return (-1);
	// if (is_digit(temp) == -1 && temp[0] != '-')
	// {
	// 	printf("faile is_digit\n");
	// 	return (-1);
	// }
	// *x = ft_atof(temp);
	
	
	// temp = ft_strtok(NULL, ',');
	// if (!temp)
	// 	return (-1);
	// if (is_digit(temp) == -1 && temp[0] != '-')
	// 	return (-1);
	// *y = ft_atof(temp);
	// temp = ft_strtok(NULL, ',');

	// //temp -1
	// if (!temp)
	// 	return (-1);
	// if (is_digit(temp) == -1 && temp[0] != '-')
	// {
	// 	return (-1);
	// }
	// *z = ft_atof(temp);

	char **temp = ft_split(token, ',');
    if (!temp || count_array_elem(temp) != 3)
	{
		//free all exit(1);
        return -1;
		//release_garbage(garbage_lst);
	}
	// add_to_garbage_list(garbage_lst, do_malloc(temp, garbage_lst));
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
	while(to_free[i])
	{
		free(to_free[i]);
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
	while(token[i])
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
float	ft_atof(char *str)
{
	double		num;
	int			sign;
	double		div;
	double		frac;

	div = 1.0;
	frac = 0.0;
	sign = 1;
	num = 0.0;
	
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	if (*str == '.')
	{
		str++;
		while (*str >= '0' && *str <= '9')
		{
			float temp = (*str - '0');
			div *= 10.0;
			frac += temp / div;
			str++;
		}
	}
	return ((frac + num) * sign);
}
