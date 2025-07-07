/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 19:45:40 by tfarkas           #+#    #+#             */
/*   Updated: 2025/01/21 16:18:35 by tfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int ch)
{
	if (ch >= 'A' && ch <= 'Z')
		ch = ch + 32;
	return (ch);
}
/* #include <stdio.h>

int	main(void)
{
	char c1;
	char c2;
	char c3;

	c1 = 'e';
	c2 = 'h';
	c3 = 'Z';
	printf("this is the character:  %c\n", ft_tolower(c1));
	printf("this is the character:  %c\n", ft_tolower(c2));
	printf("this is the character:  %c\n", ft_tolower(c3));
	return(0);
}*/
