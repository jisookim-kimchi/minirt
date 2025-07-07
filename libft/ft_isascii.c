/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:02:47 by tfarkas           #+#    #+#             */
/*   Updated: 2025/01/21 16:16:01 by tfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int ch)
{
	if (ch >= 0 && ch <= 127)
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
	printf("The given character's result: %d\n", ft_isascii(giv1));
	printf("The given character's result: %d\n", ft_isascii(giv2));
	printf("The given character's result: %d\n", ft_isascii(giv3));
	printf("The given character's result: %d\n", ft_isascii(giv4));
	return (0);
}
*/
