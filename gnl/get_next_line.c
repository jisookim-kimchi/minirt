/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 19:08:39 by jisokim2          #+#    #+#             */
/*   Updated: 2024/11/24 18:44:58 by jisokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	copy_data(char **line, char *static_buffer, size_t len, size_t *i)
{
	*line = malloc ((len + 1) * sizeof(char));
	if (!(*line))
		return (1);
	while (static_buffer[*i] && *i < len)
	{
		(*line)[*i] = static_buffer[*i];
		(*i)++;
	}
	(*line)[*i] = '\0';
	return (0);
}

int	read_buffer(int fd, char *static_buffer, int *error)
{
	if (static_buffer[0] == '\0')
		*error = read(fd, static_buffer, BUFFER_SIZE);
	return (*error);
}

void	shift_buffer(char *static_buffer, size_t i)
{
	int	j;

	j = 0;
	if (i >= BUFFER_SIZE)
	{
		while (j < BUFFER_SIZE + 1)
			static_buffer[j++] = '\0';
	}
	else
	{
		while (i < BUFFER_SIZE)
			static_buffer[j++] = static_buffer[i++];
		static_buffer[j] = '\0';
		while (j < BUFFER_SIZE)
			static_buffer[j++] = '\0';
	}
}

int	create_line(char **line, char *static_buffer, size_t len, size_t *i)
{
	char	*line2;
	char	*temp;

	if (*line == NULL)
	{
		if (copy_data(line, static_buffer, len, i))
			return (1);
	}
	else
	{
		if (copy_data(&line2, static_buffer, len, i))
			return (free(*line), 1);
		temp = ft_strjoin(*line, line2);
		free(*line);
		free(line2);
		if (!temp)
			return (1);
		*line = temp;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	static_buffer[BUFFER_SIZE + 1];
	char		*line;
	size_t		len_i[2];
	int			error;

	error = 0;
	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (static_buffer[0] || (read_buffer(fd, static_buffer, &error)) > 0)
	{
		len_i[1] = 0;
		len_i[0] = get_buffer_len(static_buffer);
		if (create_line(&line, static_buffer, len_i[0], &len_i[1]))
			return (NULL);
		shift_buffer(static_buffer, len_i[1]);
		if (line[ft_strlen(line) - 1] == '\n')
			break ;
	}
	if (had_read_error(line, error))
		return (NULL);
	return (line);
}
