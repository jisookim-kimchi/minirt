/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 13:42:41 by tfarkas           #+#    #+#             */
/*   Updated: 2025/09/02 17:43:12 by tfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../parser/parser.h"
#include "../mlx_tools.h"

void	clean_list_and_terminate(t_window *win)
{
	if (win->mlx)
		mlx_terminate(win->mlx);
	if (win->objs)
		free_objs_list(&win->objs);
	win->objs = NULL;
	printf(YELLOW"The cleanup finished before exiting.\n"DEFAULT);
	exit(1);
}

void	error_window(t_window *win)
{
	ft_putendl_fd((char *)mlx_strerror(mlx_errno), 2);
	if (win->mlx)
		mlx_terminate(win->mlx);
	exit(1);
}

char	*check_file_arg(int argc, char **argv)
{
	char	*filename;

	if (argc != 2)
	{
		printf(RED);
		ft_putendl_fd("Please give one filename!", 2);
		printf(DEFAULT);
		exit(1);
	}
	if (ft_strncmp(argv[1], "file/", 5) == 0)
	{
		filename = (char *)malloc((ft_strlen(argv[1]) + 1) * sizeof(char));
		ft_strlcpy(filename, argv[1], (ft_strlen(argv[1]) + 1));
	}
	else
		filename = ft_strjoin("file/", argv[1]);
	return (filename);
}

void	init_window(t_window *win)
{
	t_transform_comp	transform_comp;

	transform_comp = init_transform_comp();
	win->screen = make_screen(1200, 800);
	win->camera = init_camera(win->screen, transform_comp);
	win->camera.transform_comp.forward = (t_vec3){0, 0, -1};
	win->objs = NULL;
	win->mlx = NULL;
	win->image = NULL;
	win->antialisign.antialisign_text = NULL;
}
