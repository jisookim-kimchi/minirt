/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 18:47:54 by tfarkas           #+#    #+#             */
/*   Updated: 2025/08/27 21:06:20 by tfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser/parser.h"

void	error_window(t_window *win)
{
	ft_putendl_fd((char *)mlx_strerror(mlx_errno), 2);
	if (win->mlx)
		mlx_terminate(win->mlx);
}

void	ft_key_hook(mlx_key_data_t keydata, void *param)
{
	t_window	*win;
	double		delta_move;

	win = (t_window *)param;
	delta_move = 0.05;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(win->mlx);
	if (keydata.key == MLX_KEY_O && keydata.action == MLX_PRESS)
		win->antialisign_on = true;
	if (keydata.key == MLX_KEY_P && keydata.action == MLX_PRESS)
		win->antialisign_on = false;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
	{
		add_transform_comp_position(&win->camera.transform_comp, vec3(0, -1.0 * delta_move, 0));
		print_camera_infos(&win->camera);
	}
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
	{
		add_transform_comp_position(&win->camera.transform_comp, vec3(0, delta_move, 0));
		print_camera_infos(&win->camera);
	}
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
	{
		add_transform_comp_position(&win->camera.transform_comp, vec3(-1.0 *delta_move, 0, 0));
		print_camera_infos(&win->camera);
	}
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
	{
		add_transform_comp_position(&win->camera.transform_comp, vec3(delta_move, 0, 0));
		print_camera_infos(&win->camera);
	}
	if (keydata.key == MLX_KEY_R && keydata.action == MLX_PRESS)
	{
		set_transform_comp_position(&win->camera.transform_comp, vec3(0, 0, 0));
		print_camera_infos(&win->camera);
	}
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
	{
		add_transform_comp_position(&win->camera.transform_comp, vec3(0, 0, delta_move));
		print_camera_infos(&win->camera);
	}
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
	{
		add_transform_comp_position(&win->camera.transform_comp, vec3(0, 0, -1.0 * delta_move));
		print_camera_infos(&win->camera);
	}
}

/*
	The color layout: 0xAARRGGBB
	AA = Alpha (opacity)
	RR = Red
	GG = Green
	BB = Blue

	The blue color made to check if the window can run. However it the 
	final version it should be deleted.
*/

void	image_hook(void *param)
{
	t_window	*win;
	uint32_t	x;
	uint32_t	y;
	// uint32_t	blue;
	t_color_32	pixel_center_col;
	t_ray		ray_pixel_center;

	win = (t_window *)param;

	y = 0;
	while (y < win->image->height)
	{
		x = 0;
		while (x < win->image->width)
		{
			get_ray_from_camera(&win->camera, &ray_pixel_center, x, y);
			pixel_center_color(&ray_pixel_center, win, &pixel_center_col);
			mlx_put_pixel(win->image, x, y, pixel_center_col.result_color);
			x++;
		}
		y++;
	}
	if (win->antialisign_on == true)
		mlx_put_string(win->mlx, "Antialiasign", 5, 5);
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

int	main(int argc, char **argv)
{
	//todo make init function for t_window
	t_window			win;

	t_screenpoint		screen;
	t_transform_comp	transform_comp;
	
	transform_comp = init_transform_comp();
	screen = make_screen(1200, 800);
	win.camera = init_camera(screen, transform_comp);
	win.camera.transform_comp.forward = (t_vec3){0,0,-1};
	win.objs = NULL;

	/* parsing start */
	char *path = check_file_arg(argc, argv);
	if (!is_valid_file(path))
	{
		printf(RED"non valid file\n"DEFAULT);
		return (-1);
	}
	int fd = open_file(path);
	if (fd < 0)
	{
		printf(RED"file open failed\n"DEFAULT);
		return (-1);
	}
	int check_read = read_file(fd, &win);
	win.spot_light = init_spot_light(&win.light, (t_vec3){0,-1,0}, 1000.0, 60.0, 50.0);
	if (check_read < 0)
	{
		free_objs_list(&win.objs);
		printf("failed parsing\n");
		exit(1);
	}
	
	win.mlx = mlx_init(IMAGE_WIDTH, IMAGE_WIDTH / IMAGE_RATIO, argv[1] , true);
	if (!win.mlx)
	{
		printf("error mlx_init\n");
		error_window(&win);
	}
	win.image = mlx_new_image(win.mlx, \
		(int32_t)screen.x, (int32_t)(screen.y));
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	
	/* image rendering start */
	image_hook(&win);
	if (!win.image || (mlx_image_to_window(win.mlx, win.image, 0, 0) < 0))
	{
		printf("error mlx_image or mlx_image_to_window\n");
		error_window(&win);
	}
	if (mlx_loop_hook(win.mlx, image_hook, &win) == false)
	 	error_window(&win);
	mlx_key_hook(win.mlx, ft_key_hook, &win);
	mlx_loop(win.mlx);

	mlx_terminate(win.mlx);

	free_objs_list(&win.objs);
	exit (0);
	return (0);
}
