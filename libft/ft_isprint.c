/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:44:08 by tfarkas           #+#    #+#             */
/*   Updated: 2025/01/21 16:16:07 by tfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int ch)
{
	if (ch >= 32 && ch <= 126)
		return (1);
	return (0);
}
/*#include <stdio.h>

int	main(void)
{
	int	giv1;
	int	giv2;
	int	giv3;
	int	giv4;
	int giv5;

	giv1 = 'A';
	giv2 = 'b';
	giv3 = '\\';
	giv4 = '1';
	giv5 = 15;
	printf("The given character's result: %d\n", ft_isprint(giv1));
	printf("The given character's result: %d\n", ft_isprint(giv2));
	printf("The given character's result: %d\n", ft_isprint(giv3));
	printf("The given character's result: %d\n", ft_isprint(giv4));
	printf("The given character's result: %d\n", ft_isprint(giv5));
	return (0);
}*/
