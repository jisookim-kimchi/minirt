/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 15:16:46 by tfarkas           #+#    #+#             */
/*   Updated: 2025/01/21 16:15:38 by tfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(unsigned int numcount, unsigned int bsize)
{
	unsigned char	*ptr;
	unsigned int	i;

	i = 0;
	ptr = (unsigned char *)malloc(numcount * bsize);
	if (ptr == (unsigned char *)0)
		return ((unsigned char *)0);
	while (i < numcount * bsize)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
/*#include <stdio.h>

int	main(void)
{
	unsigned char    *ptr;

	ptr = ft_calloc(2, 3);
	printf("This is the allocated memory: \n%s\n", ptr);
	return(0);
}*/
