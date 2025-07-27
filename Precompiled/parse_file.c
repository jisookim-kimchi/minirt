/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 10:40:28 by jisokim2          #+#    #+#             */
/*   Updated: 2025/07/27 11:08:36 by jisokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "loadresource.h"

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
	return (-1);
}

/*  //todo
	read_file in progress
*/
int	read_file(int fd)
{
	ssize_t	read_size;
	char	*line;
	int		result;

	while (1)
	{
		*line = get_next_line(fd);
		if (!line)
			break;
		result = parsing_start(line);
		if (result < 0)
		{
			break;
		}
		free(line);
	}
	return (result);
}

int main(void)
{
	char *path = "../";
	if (!is_valid_file(path));
		return (-1);
	int fd = open_file(path);
	int check_read = read_file(fd);
	
	return (0);
}