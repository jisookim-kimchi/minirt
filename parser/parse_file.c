/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 10:40:28 by jisokim2          #+#    #+#             */
/*   Updated: 2025/08/31 20:08:51 by tfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

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

static int	is_acl_one_while(int fd, int *a, int *c, int *l)
{
	char	*line;

	line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (ft_strncmp("A", line, 1) == 0)
			(*a)++;
		else if (ft_strncmp("C", line, 1) == 0)
			(*c)++;
		else if (ft_strncmp("L", line, 1) == 0)
			(*l)++;
		free(line);
	}
	return (1);
}

static int	is_acl_one(int fd, char *path)
{
	int		a;
	int		c;
	int		l;

	a = 0;
	c = 0;
	l = 0;
	is_acl_one_while(fd, &a, &c, &l);
	if (a != 1 || c != 1 || l != 1)
	{
		printf(RED"ERROR: number of ACL is not correct:\n"
			"Ambient light: %d, Camera: %d, Light: %d\n"DEFAULT, a, c, l);
		return (close(fd), -1);
	}
	close(fd);
	fd = open_file(path);
	return (1);
}

/*
	This was the if part before using the is_acl_one function

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
*/
int	read_file(int fd, t_window *window, char *path)
{
	char	*line;
	int		result;

	line = NULL;
	result = 0;
	if (is_acl_one(fd, path) < 0)
		exit(1);
	printf(GREEN"Start save data from file\n"DEFAULT);
	while (1)
	{
		line = get_next_line(fd);
		printf("parsed line : %s\n", line);
		if (!line)
		{
			break ;
		}
		result = handle_line(line, window);
	}
	printf(YELLOW"EOF reached\n"DEFAULT);
	return (result);
}
