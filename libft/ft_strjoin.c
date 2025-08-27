/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:12:59 by tfarkas           #+#    #+#             */
/*   Updated: 2025/01/21 16:17:38 by tfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		s1len;
	int		s2len;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	ptr = (char *)malloc((s1len + s2len + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, s1, s1len + 1);
	ft_strlcat(ptr, s2, s1len + s2len + 1);
	return (ptr);
}
/*#include <stdio.h>

int	main(void)
{
    char    s1[] = "- hello";
    char    s2[] = "12 world";
    char    *ptr;

    ptr = ft_strjoin(s1, s2);
    printf("This is the concatenated string: \n%s\n", ptr);
    free(ptr);
    return (0);
}*/
