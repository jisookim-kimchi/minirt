/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 19:42:08 by tfarkas           #+#    #+#             */
/*   Updated: 2025/08/31 19:58:06 by tfarkas          ###   ########.fr       */
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

char	*ft_strtok(char *str, const char c)
{
	static char	*input;
	char		*start;
	int			i;

	i = 0;
	if (str)
		input = str;
	if (!input || !*input)
		return (NULL);
	start = input;
	while (input[i] && input[i] != c && input[i] != '\n')
		i++;
	if (input[i])
	{
		input[i] = '\0';
		input = &input[i + 1];
	}
	else
		input = NULL;
	return (start);
}

int	count_array_elem(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		i++;
	}
	return (i);
}
