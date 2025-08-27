/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:18:02 by tfarkas           #+#    #+#             */
/*   Updated: 2025/01/21 16:15:46 by tfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int ch)
{
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		return (1);
	return (0);
}

/* #include <stdio.h>

int main(void)
{
	int giv1 = 'A';
	int giv2 = 'b';
	int giv3 = '\\';
	int giv4 = '1';
	// int giv5 = 'ि';

	printf("The given character's result: %d\n", ft_isalpha(giv1));
	printf("The given character's result: %d\n", ft_isalpha(giv2));
	printf("The given character's result: %d\n", ft_isalpha(giv3));
	printf("The given character's result: %d\n", ft_isalpha(giv4));
	// printf("The given character's result: %d\n", ft_isalpha(giv5));

	return(0);
}
*/
