/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:24:21 by tfarkas           #+#    #+#             */
/*   Updated: 2025/01/21 15:51:54 by tfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int ch)
{
	if ((ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'Z') || (ch >= 'a'
			&& ch <= 'z'))
		return (1);
	return (0);
}
/* #include <stdio.h>

int	main(void)
{
	int	giv1;
	int	giv2;
	int	giv3;
	int	giv4;

	giv1 = 'A';
	giv2 = 'b';
	giv3 = '\\';
	giv4 = '1';
	printf("The given character's result: %d\n", ft_isalnum(giv1));
	printf("The given character's result: %d\n", ft_isalnum(giv2));
	printf("The given character's result: %d\n", ft_isalnum(giv3));
	printf("The given character's result: %d\n", ft_isalnum(giv4));
	return (0);
}*/
