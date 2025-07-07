/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 12:04:20 by tfarkas           #+#    #+#             */
/*   Updated: 2025/01/21 16:18:13 by tfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *orig_s, const char *search_s, unsigned int n)
{
	unsigned int	i;
	unsigned int	j;

	j = 0;
	i = 0;
	if (search_s[i] == '\0')
		return ((char *)&orig_s[i]);
	while (j < n && orig_s[j] != '\0')
	{
		while (orig_s[j + i] == search_s[i] && orig_s[j + i] != '\0' && j
			+ i < n)
		{
			i++;
			if (search_s[i] == '\0')
				return ((char *)&orig_s[j]);
		}
		j++;
		i = 0;
	}
	return ((char *)0);
}
/*#include <stdio.h>

int	main(void)
{
	const char		orig_str[] = "lorem ipsum dolor sit amet";
	const char		search_str[] = "ipsum";
	unsigned int	n;
	const char		*ptr1;
	const char		*ptr2;

	n = 15;
	ptr1 = orig_str;
	ptr2 = ft_strnstr(orig_str, search_str, n);
	if (ptr2 != (void *)0)
		printf("The founded place is: %ld\n", ptr2 - ptr1);
	else
		printf("%s does not find in string %s\n", search_str, orig_str);
	return (0);
}*/
