/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:10:07 by tfarkas           #+#    #+#             */
/*   Updated: 2025/01/21 16:16:22 by tfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			f_intlen(int n);
static char			*f_wpozitive(long long n, int intlen);
static long long	f_abs(int n);

char	*ft_itoa(int n)
{
	char	*nptr;
	char	*nptrw;

	nptrw = f_wpozitive(f_abs(n), f_intlen(f_abs(n)));
	if (nptrw == NULL)
		return (NULL);
	if (n < 0)
	{
		nptr = ft_strjoin("-", nptrw);
		if (nptr == NULL)
		{
			free(nptrw);
			return (NULL);
		}
		free(nptrw);
	}
	else
		nptr = nptrw;
	return (nptr);
}

static int	f_intlen(int n)
{
	int	intcharcount;

	intcharcount = 0;
	if (n == 0)
		intcharcount++;
	while (n != 0)
	{
		n = n / 10;
		intcharcount++;
	}
	return (intcharcount);
}

static char	*f_wpozitive(long long n, int intlen)
{
	char	*nptr;
	int		i;

	i = intlen - 1;
	if (n == 0)
	{
		nptr = (char *)malloc(2 * sizeof(char));
		if (nptr == NULL)
			return (NULL);
		nptr[0] = '0';
		nptr[1] = '\0';
		return (nptr);
	}
	nptr = (char *)malloc((intlen + 1) * sizeof(char));
	if (nptr == NULL)
		return (NULL);
	while (n != 0)
	{
		nptr[i] = ((n % 10) + 48);
		n = n / 10;
		i--;
	}
	nptr[intlen] = '\0';
	return (nptr);
}

static long long	f_abs(int n)
{
	long long	absn;

	absn = (long long)n;
	if (n < 0)
		return (-1 * absn);
	return (absn);
}
/*#include <stdio.h>

int	main(void)
{
	int		num;
	char	*nptr;

	num = -2147483648;
	nptr = ft_itoa(num);
	ft_putendl_fd(nptr, 1);
	printf("This is the integer: \n%s\n", nptr);
	// free(nptr);
	return (0);
}*/
