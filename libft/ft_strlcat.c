/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:36:59 by tfarkas           #+#    #+#             */
/*   Updated: 2025/01/21 16:19:56 by tfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcat(char *dest, const char *src, unsigned int destsize)
{
	unsigned int	srclen;
	unsigned int	destlen;

	srclen = ft_strlen(src);
	destlen = ft_strlen(dest);
	if (destlen >= destsize)
		return (srclen + destsize);
	if (srclen + destlen < destsize)
		ft_strlcpy(dest + destlen, src, srclen + 1);
	else
	{
		ft_strlcpy(dest + destlen, src, destsize - destlen);
	}
	return (srclen + destlen);
}
