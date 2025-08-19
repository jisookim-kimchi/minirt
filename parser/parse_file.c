/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 10:40:28 by jisokim2          #+#    #+#             */
/*   Updated: 2025/08/19 15:50:44 by tfarkas          ###   ########.fr       */
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
int	read_file(int fd, t_window *window)
{
	char		*line;
	int			result;

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
			else
			{	
				printf("EOF reached.\n");
				break;
			}	
			return 0;
		}
		if (*line == '\n' || *line == '#')
		{
			free(line);
			continue;
		}
		result = parsing_start(line, window);
		if (result < 0)
		{
			free_objs_list(&window->objs);
			free(line);
			exit(1);
		}
		free(line);
	}
	return (result);
}

// int main(void)
// {
// 	char *path = "../";
// 	if (!is_valid_file(path))
// 		return (-1);
// 	int fd = open_file(path);
// 	int  = read_file(fd);
	
// 	return (0);
// }