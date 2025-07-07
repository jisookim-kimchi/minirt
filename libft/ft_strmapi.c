/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:56:30 by tfarkas           #+#    #+#             */
/*   Updated: 2025/01/21 16:18:03 by tfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ptr;
	int		i;
	int		strlen;

	i = 0;
	strlen = ft_strlen(s);
	ptr = (char *)malloc((strlen + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		ptr[i] = (*f)(i, s[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
/*char	f_repl_every_fourth(unsigned int i, char c)
{
	if (i % 4 == 0)
		c = '0';
	return (c);
}
#include <stdio.h>

int	main(void)
{
	char	*str;

	str = ft_strmapi("hello world", f_repl_every_fourth);
	printf("This is the result string: \n%s\n", str);
	free(str);
	return (0);
}*/
