/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 20:29:20 by tfarkas           #+#    #+#             */
/*   Updated: 2025/01/21 16:16:27 by tfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int ch, unsigned int n)
{
	unsigned char	*srcptr;
	unsigned int	i;

	i = 0;
	srcptr = (unsigned char *)src;
	while (i < n)
	{
		if (srcptr[i] == (unsigned char)ch)
			return ((void *)&srcptr[i]);
		i++;
	}
	return ((void *)0);
}
/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	const char str[] = "Hello Tamas, how are you?";
	char ch = 'D';
	char *ptr;

	ptr = ft_memchr(str, ch, strlen(str));
	if (ptr != NULL)
		printf("Character '%c' found at position: %ld\n", ch, ptr - str);
	else
		printf("Character '%c' not found\n", ch);
	return (0);
}*/
