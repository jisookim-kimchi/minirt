/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 18:11:56 by tfarkas           #+#    #+#             */
/*   Updated: 2025/01/21 16:16:46 by tfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int ch, unsigned int len)
{
	unsigned char	*ptr;
	unsigned int	i;

	ptr = str;
	i = 0;
	while (i < len)
	{
		ptr[i] = (unsigned char)ch;
		i++;
	}
	return (str);
}
/* #include <stdio.h>

int	main(void)
{
	char bin[20];
	int len;
	int i;
	len = 7;
	i = 0;

	ft_memset(bin, 'z', len);

	while (i < len)
	{
		printf("%c", bin[i]);
		i++;
	}
	return(0);
}*/
