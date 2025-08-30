/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 10:40:28 by jisokim2          #+#    #+#             */
/*   Updated: 2025/08/30 20:16:25 by tfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
	check the file extension.
*/
bool	is_valid_file(char *path)
{
	int	check;

	check = 0;
	if (!path || ft_strlen(path) <= 3)
		return (false);
	check = ft_strlen(path) - 3;
	if (ft_strncmp(path + check, ".rt", 3) == 0)
	{
		return (true);
	}
	return (false);
}

/*
	open_file
*/
int	open_file(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		perror("FILE OPEN FAILED");
		exit(1);
	}
	return (fd);
}

/*  //todo
	read_file in progress
*/
static int	handle_line(char *line, t_window *window)
{
	int	result;

	if (*line == '\n' || *line == '#')
	{
		free(line);
		return (1);
	}
	result = parsing_start(line, window);
	if (result < 0)
	{
		printf("parsing_start() error\n");
		free_objs_list(&window->objs);
		free(line);
		exit(1);
	}
	free(line);
	return (result);
}

int	read_file(int fd, t_window *window)
{
	char	*line;
	int		result;

	line = NULL;
	result = 0;
	while (1)
	{
		line = get_next_line(fd);
		printf("parsed line : %s\n", line);
		if (!line)
		{
			if (result == 0)
			{
				printf("no line\n");
				return (-1);
			}
			printf("EOF reached.\n");
			break ;
		}
		result = handle_line(line, window);
	}
	return (result);
}
