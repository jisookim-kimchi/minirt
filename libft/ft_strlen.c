/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:13:28 by tfarkas           #+#    #+#             */
/*   Updated: 2025/01/21 16:17:59 by tfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(const char *s)
{
	int	n;

	n = 0;
	while (*s != '\0')
	{
		n++;
		s++;
	}
	return (n);
}
/* #include <stdio.h>

int	main(void)
{
	char	*str;

	str = "hello world12304";
	printf("The given string is: %s\n", str);
	printf("The length of the given string is: %d\n", ft_strlen(str));
	return(0);
}
*/
