/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:24:09 by tfarkas           #+#    #+#             */
/*   Updated: 2025/01/21 16:14:13 by tfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	num = 0;
	sign = 1;
	if (*str == 0)
		return (0);
	while (ft_strchr(" \t\r\n\v\f", str[i]) != (char *)0)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_strchr("0123456789", str[i]) != (char *)0 && str[i] != '\0')
	{
		num = 10 * num + (str[i] - '0');
		i++;
	}
	num = sign * num;
	return (num);
}
/*#include <stdio.h>

int	main(void)
{
	char    str[] = "0";
	int     numb;

	numb = ft_atoi(str);
	printf("The number read out: \n%d\n", numb);
	return(0);
}*/
