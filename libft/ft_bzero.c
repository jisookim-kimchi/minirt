/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:36:39 by tfarkas           #+#    #+#             */
/*   Updated: 2025/01/21 16:15:35 by tfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, unsigned int len)
{
	unsigned char	*ptr;
	unsigned int	i;

	ptr = (unsigned char *)str;
	i = 0;
	while (i < len)
	{
		ptr[i] = 0;
		i++;
	}
}
/* #include <stdio.h>

int	main(void)
{
	char bin[]="123456789";
	int len;
    int siz;
	int i;

	len = 5;
    siz = sizeof(bin);
	i = 0;
	ft_bzero(bin, len);
	while (i < siz)
	{
		printf("%c", bin[i]);
		i++;
	}
	return(0);
}*/
