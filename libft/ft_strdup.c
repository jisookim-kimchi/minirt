/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 09:59:33 by tfarkas           #+#    #+#             */
/*   Updated: 2025/01/21 16:17:25 by tfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	unsigned char	*ptr;
	unsigned long	i;
	unsigned long	strlenclosed;

	strlenclosed = ft_strlen(str) + 1;
	ptr = (unsigned char *)malloc(strlenclosed);
	if (ptr == (unsigned char *)0)
		return ((char *)0);
	i = 0;
	while (i < strlenclosed - 1)
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return ((char *)ptr);
}
/*#include <stdio.h>

int	main(void)
{
	const char  str[] = "hello, please save it!";
	char        *saveptr;

	saveptr = ft_strdup(str);
	printf("This is the saved string: \n%s\nAnd This is the adress: \n%p\n",
		saveptr, saveptr);
	return (0);
}*/
