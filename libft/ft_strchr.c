/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:02:58 by tfarkas           #+#    #+#             */
/*   Updated: 2025/01/21 16:17:21 by tfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int ch)
{
	int				i;
	unsigned char	ch1;

	ch1 = (unsigned char)ch;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ch1)
			return ((char *)&s[i]);
		i++;
	}
	if (ch1 == '\0')
		return ((char *)&s[i]);
	return ((char *)0);
}
/*#include <stdio.h>

int	main(void)
{
	const char str[] = "hello Tamas";
	char ch = 'T';

	printf("this is the first occurance of '%c' character: \n%s\n", ch,
		ft_strchr(str, ch));
	return(0);
}*/
