/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 12:35:52 by jisokim2          #+#    #+#             */
/*   Updated: 2025/08/29 12:38:42 by jisokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

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
