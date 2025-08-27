/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 09:58:59 by tfarkas           #+#    #+#             */
/*   Updated: 2025/01/21 16:17:29 by tfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		(*f)(i, &s[i]);
		i++;
	}
}
/*void	f_modstr(unsigned int i, char *s)
{
	*s += 1 + i;
}
#include <stdio.h>

int	main(void)
{
	char	str[] = "Hello Tamas";

	ft_striteri(str, f_modstr);
	printf("This is the changed string: \n%s\n",str);
	return (0);
}*/
