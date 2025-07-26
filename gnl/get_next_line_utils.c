/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 19:11:29 by jisokim2          #+#    #+#             */
/*   Updated: 2024/11/24 18:40:09 by jisokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i] != '\0')
		i++;
	return (i);
}

static size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	src_len;
	size_t	i;

	i = 0;
	src_len = ft_strlen(src);
	if (n == 0)
		return (src_len);
	while (n - 1 > 0 && src[i])
	{
		dst[i] = src[i];
		i++;
		n--;
	}
	dst[i] = '\0';
	return (src_len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*temp_r;
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;
	size_t	j;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	i = 0;
	j = 0;
	temp_r = malloc(((len_s1 + len_s2) + 1) * sizeof(char));
	if (!temp_r)
		return (NULL);
	ft_strlcpy(temp_r, s1, len_s1 + 1);
	ft_strlcpy(temp_r + len_s1, s2, len_s2 + 1);
	return (temp_r);
}

size_t	get_buffer_len(char *buff)
{
	size_t	i;

	i = 0;
	while (buff[i] != '\0' && buff[i] != '\n')
		i++;
	if (buff[i] == '\n')
		i++;
	return (i);
}

int	had_read_error(char *line, int error)
{
	if (error < 0)
	{
		if (line)
			free(line);
		return (1);
	}
	return (0);
}
