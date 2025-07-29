/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 10:40:28 by jisokim2          #+#    #+#             */
/*   Updated: 2025/07/29 16:52:21 by jisokim2         ###   ########.fr       */
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
	char	*line;
	int		result;

	line = NULL;
	result = 0;

	while (1)
	{
		line = get_next_line(fd);
		printf("line : %s\n", line);
		if (!line)
			break;
		if (*line == '\n')
			continue;
		result = parsing_start(line, window);
		printf("result %d\n", result);
		if (result < 0)
		{
			//garbage collector.
			//perror();
			//exit(1);
			break;
		}
		free(line);
	}
	// fclose(fp);
	return (result);
}

// int main(void)
// {
// 	char *path = "../";
// 	if (!is_valid_file(path))
// 		return (-1);
// 	int fd = open_file(path);
// 	int check_read = read_file(fd);
	
// 	return (0);
// }