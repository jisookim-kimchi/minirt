/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 13:32:37 by tfarkas           #+#    #+#             */
/*   Updated: 2025/01/21 16:17:53 by tfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcpy(char *dest, const char *src, unsigned int destsize)
{
	unsigned int	i;
	unsigned int	srcsize;

	i = 0;
	srcsize = ft_strlen(src);
	if (srcsize + 1 < destsize)
	{
		while (i < srcsize + 1)
		{
			dest[i] = src[i];
			i++;
		}
	}
	else if (destsize != 0)
	{
		while (i < destsize - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (srcsize);
}
/* #include <stdio.h>

int	main(void)
{
	char            src[] = "Good";
	char            dest[] = "How are you?";
	unsigned int    srclen;

	srclen = ft_strlcpy(dest, src, sizeof(dest) + 1);
	printf("The modified destination: \n%s\nThe length of the source:
		%d\n",dest, srclen);
	return(0);
}*/
