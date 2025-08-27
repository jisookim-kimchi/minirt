/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:00:05 by tfarkas           #+#    #+#             */
/*   Updated: 2025/01/21 16:15:14 by tfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int ch)
{
	if (ch >= '0' && ch <= '9')
		return (1);
	return (0);
}
/* #include <stdio.h>

int  main(void)
{
    int giv1 = 'A';
	int giv2 = 'b';
	int giv3 = '\\';
	int giv4 = '1';

    printf("The given character's result: %d\n", ft_isdigit(giv1));
    printf("The given character's result: %d\n", ft_isdigit(giv2));
    printf("The given character's result: %d\n", ft_isdigit(giv3));
    printf("The given character's result: %d\n", ft_isdigit(giv4));

    return(0);
}
*/
