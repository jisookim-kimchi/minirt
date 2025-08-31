/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 10:40:28 by jisokim2          #+#    #+#             */
/*   Updated: 2025/08/31 16:17:19 by tfarkas          ###   ########.fr       */
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
		perror(RED"FILE OPEN FAILED"DEFAULT);
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

// static int	is_ACL_one(int fd)
// {
// 	char	*line;
// 	int		a;
// 	int		c;
// 	int		l;

// 	a = 0;
// 	c = 0;
// 	l = 0;
// 	line = NULL;
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (!line)
// 			break ;
// 		if (ft_strncmp("A" ,line, 1) == 0)
// 			a++;
// 		else if (ft_strncmp("C" ,line, 1) == 0)
// 			c++;
// 		else if (ft_strncmp("L" ,line, 1) == 0)
// 			l++;
// 		free(line);
// 	}
// 	if (a != 1 || c != 1 || l != 1)
// 		return (-1);
// 	return (1);
// }

int	read_file(int fd, t_window *window)
{
	char	*line;
	int		result;

	line = NULL;
	result = 0;
	// if (is_ACL_one(fd) < 0)
	// {
	// 	printf("is_ACL_one error\n");
	// 	exit(1);
	// }
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
	// printf("EOF reached\n");
	return (result);
}

