/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:18:15 by tfarkas           #+#    #+#             */
/*   Updated: 2025/01/21 16:18:21 by tfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int ch)
{
	int				i;
	int				j;
	unsigned char	ch1;

	ch1 = (unsigned char)ch;
	i = 0;
	j = -1;
	while (s[i] != '\0')
	{
		if (s[i] == ch1)
			j = i;
		i++;
	}
	if (ch1 == '\0')
		return ((char *)&s[i]);
	else if (j != -1)
		return ((char *)&s[j]);
	return ((char *)0);
}
/*#include <stdio.h>

int	main(void)
{
	const char str[] = "Tamas, Tamas, come here!";
	char        ch = 'T';

	printf("this is the last occurance of '%c' character: \n%s\n", ch,
		ft_strrchr(str, ch));
	return(0);
}*/
