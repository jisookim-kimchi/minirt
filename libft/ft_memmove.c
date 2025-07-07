/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:01:43 by tfarkas           #+#    #+#             */
/*   Updated: 2025/01/21 16:16:42 by tfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, unsigned int n)
{
	unsigned char		*destptr;
	const unsigned char	*srcptr;
	unsigned int		i;

	i = 0;
	if ((dest == (void *)0 && src == (void *)0) || n == 0)
		return (dest);
	destptr = (unsigned char *)dest;
	srcptr = (const unsigned char *)src;
	if (srcptr < destptr && destptr < (srcptr + n))
	{
		while (n-- > 0)
			destptr[n] = srcptr[n];
	}
	else
	{
		while (i < n)
		{
			destptr[i] = srcptr[i];
			i++;
		}
	}
	return (dest);
}
/* #include <stdio.h>

int	main(void)
{
	char	init[] = "Hello world";
	char	destination[] = "Good morning! Have a nice day!";

	ft_memmove(destination, init, 7);
	printf("This is the word: \n%s\n", destination);
	return (0);
}*/
