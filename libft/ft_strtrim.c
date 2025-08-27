/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 09:41:32 by tfarkas           #+#    #+#             */
/*   Updated: 2025/01/21 16:22:54 by tfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	f_lastoccurence(char const *s1, char const *set);
static int	f_si_isin_set(char const *set, char const si);
static char	*f_backcopy(char const *str);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*mptr1;
	char	*backcopy;
	int		beginidx;
	int		endidx;
	int		s1len;

	beginidx = 0;
	endidx = 0;
	s1len = ft_strlen(s1);
	beginidx = f_lastoccurence(s1, set);
	backcopy = f_backcopy(s1);
	if (backcopy == NULL)
		return (NULL);
	endidx = f_lastoccurence(backcopy, set);
	free(backcopy);
	mptr1 = ft_substr(s1, beginidx, (s1len - (beginidx + endidx)));
	if (mptr1 == NULL)
		return (NULL);
	return (mptr1);
}

static int	f_lastoccurence(char const *s1, char const *set)
{
	int	i;
	int	idx;

	i = 0;
	idx = 0;
	while (f_si_isin_set(set, s1[i]) == 1)
	{
		i++;
		idx++;
	}
	return (idx);
}

static int	f_si_isin_set(char const *set, char const si)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == si)
			return (1);
		i++;
	}
	return (0);
}

static char	*f_backcopy(char const *str)
{
	char	*mptr;
	int		strlen;
	int		i;

	mptr = ft_strdup(str);
	if (mptr == NULL)
		return (NULL);
	strlen = ft_strlen(str);
	i = 0;
	while (i < strlen)
	{
		mptr[i] = str[strlen - 1 - i];
		i++;
	}
	mptr[i] = '\0';
	return (mptr);
}
/*#include <stdio.h>

int	main(void)
{
	char    s1[] = "(((((";
	char    set[] = "(";
	char    *mptr;

	mptr = ft_strtrim(s1, set);
	printf("This is the trimmed string: \n'%s'\n", mptr);
	printf("This is the size of pointer: \n%lu\n", sizeof(mptr));
	printf("This is the length of string pointer: \n%d\n", ft_strlen(mptr));
	return (0);
}*/
