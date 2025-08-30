/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 18:47:54 by tfarkas           #+#    #+#             */
/*   Updated: 2025/08/30 18:59:40 by tfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser/parser.h"

static void	main_parsing_file(int argc, char **argv, t_window *win)
{
	char	*path;
	int		fd;
	int		check_read;

	path = check_file_arg(argc, argv);
	if (!is_valid_file(path))
	{
		printf(RED"non valid file\n"DEFAULT);
		exit(1);
	}
	fd = open_file(path);
	if (fd < 0)
	{
		printf(RED"file open failed\n"DEFAULT);
		exit(1);
	}
	check_read = read_file(fd, win);
	if (check_read < 0)
	{
		free_objs_list(&win->objs);
		printf("failed parsing\n");
		exit(1);
	}
}

static void	main_window_start(t_window *win, char **argv)
{
	win->mlx = mlx_init(IMAGE_WIDTH, IMAGE_WIDTH / (16.0f / 9.0f),
			argv[1], true);
	if (!win->mlx)
	{
		printf("error mlx_init\n");
		error_window(win);
	}
	win->image = mlx_new_image(win->mlx, \
		(int32_t)(win->screen.x), (int32_t)(win->screen.y));
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	image_hook(win);
	if (!win->image || (mlx_image_to_window(win->mlx, win->image, 0, 0) < 0))
	{
		printf("error mlx_image or mlx_image_to_window\n");
		error_window(win);
	}
}

int	main(int argc, char **argv)
{
	t_window			win;

	init_window(&win);
	main_parsing_file(argc, argv, &win);
	main_window_start(&win, argv);
	if (mlx_loop_hook(win.mlx, image_hook, &win) == false)
		error_window(&win);
	mlx_key_hook(win.mlx, ft_key_hook, &win);
	mlx_loop(win.mlx);
	mlx_terminate(win.mlx);
	free_objs_list(&win.objs);
	exit (0);
	return (0);
}
