/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 22:20:14 by tfarkas           #+#    #+#             */
/*   Updated: 2025/01/21 16:16:31 by tfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, unsigned int n)
{
	unsigned char	*s1ptr;
	unsigned char	*s2ptr;
	unsigned int	i;

	s1ptr = (unsigned char *)s1;
	s2ptr = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (s1ptr[i] != s2ptr[i])
			return (s1ptr[i] - s2ptr[i]);
		i++;
	}
	return (0);
}
/* #include <stdio.h>

int	main(void)
{
	const char	s1[] = "Hello have a nice day";
	const char	s2[sizeof s1] = "Hello hate a nice day";
	int			num;

	num = ft_memcmp(s1, s2, sizeof s1);
	if (num != 0)
		printf("The difference between s1 and s2: %d\n", num);
	else
		printf("There is not any difference between s1 and s2");
	return (0);
}*/
