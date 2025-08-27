/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:55:43 by tfarkas           #+#    #+#             */
/*   Updated: 2025/01/21 16:18:28 by tfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*subsptr;
	unsigned int	slength;
	size_t			i;

	slength = ft_strlen(s);
	if (start > slength || s[0] == '\0')
		return (ft_strdup(""));
	if (len > slength - start)
		len = slength - start;
	subsptr = (char *)malloc(len + 1);
	if (subsptr == NULL)
		return (NULL);
	i = 0;
	while (s[start + i] != '\0' && i < len)
	{
		subsptr[i] = s[start + i];
		i++;
	}
	subsptr[i] = '\0';
	return (subsptr);
}
/*#include <stdio.h>

int	main(void)
{
	const char s[] = "hello this is the string";
	char *subsptr;

	subsptr = ft_substr(s, 3, 4);
	printf("This is the saved substring: \n%s\n", subsptr);
	return (0);
}*/
