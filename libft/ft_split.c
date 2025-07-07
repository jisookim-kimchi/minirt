/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:05:28 by tfarkas           #+#    #+#             */
/*   Updated: 2025/01/21 16:17:16 by tfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	f_countword(char const *s, char c);
static char	*f_saveword(char const *s, char c, int *startpoz);

char	**ft_split(char const *s, char c)
{
	char	**splitarray;
	int		i;
	int		countw;
	int		startpoz;

	i = 0;
	startpoz = 0;
	countw = f_countword(s, c);
	splitarray = ft_calloc(countw + 1, sizeof(char *));
	if (splitarray == NULL || s == NULL)
		return (NULL);
	while (i < countw)
	{
		splitarray[i] = f_saveword(s, c, &startpoz);
		if (splitarray[i] == NULL)
		{
			while (i > 0)
				free(splitarray[--i]);
			free(splitarray);
			return (NULL);
		}
		i++;
	}
	splitarray[i] = NULL;
	return (splitarray);
}

static int	f_countword(char const *s, char c)
{
	int	i;
	int	countw;
	int	cdelimiter;

	i = 0;
	countw = 0;
	cdelimiter = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && cdelimiter == 0)
		{
			countw++;
			cdelimiter = 1;
		}
		else if (s[i] == c)
			cdelimiter = 0;
		i++;
	}
	return (countw);
}

static char	*f_saveword(char const *s, char c, int *startpoz)
{
	int		first;
	int		last;
	char	*sword;

	first = *startpoz;
	while (s[first] == c && s[first] != '\0')
		first++;
	last = first;
	while (s[last] != c && s[last] != '\0')
		last++;
	if (last > first)
	{
		sword = ft_substr(s, first, last - first);
		*startpoz = last;
		return (sword);
	}
	return (NULL);
}
/*#include <stdio.h>

int	main(void)
{
	char    s[] = "% w%%k%23%s";
	char    delimeter = '%';
	char    **splitarray;
	int     i;

	i = 0;
	splitarray = ft_split(s, delimeter);
	if (splitarray == NULL)
	{
		printf("Error in split\n");
		return (1);
	}
	while (splitarray[i] != NULL)
	{
		printf("This is the %d. element of array: %s\n", i, splitarray[i]);
		i++;
	}
	i = 0;
	while (splitarray[i] != NULL)
	{
		free(splitarray[i]);
		i++;
	}
	free(splitarray);
	return (0);
}*/