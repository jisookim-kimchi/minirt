/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 18:47:54 by tfarkas           #+#    #+#             */
/*   Updated: 2025/07/30 14:36:55 by jisokim2         ###   ########.fr       */
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

	win = (t_window *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(win->mlx);
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
			pixel_center_col = pixel_center_color(&ray_pixel_center, win);
			mlx_put_pixel(win->image, x, y, pixel_center_col.result_color);
			// mlx_put_pixel(win->image, x, y, blue);
			x++;
		}
		y++;
	}
}

int main(void)
{
	t_window			win;

	//Light init.
	// win.light.light_color.red = INFINITY;
	
	t_screenpoint		screen;
	t_transform_comp	transform_comp;
	// t_color_float		ambient;
	// t_color_float		light;

	transform_comp = init_transform_comp();
	screen = make_screen(1200, 800);
	win.camera = init_camera(screen, transform_comp);
	 win.camera.transform_comp.forward = (t_vec3){0,0,-1};
	win.objs = init_objs_list();

	win.mlx = mlx_init(IMAGE_WIDTH, IMAGE_WIDTH / IMAGE_RATIO, "Practice", true);
	
	// color_float_set(&ambient, 0.0f, 1.0f, 0.0f);
	// win.ambient = init_ambient(0.7f, ambient);
	// color_float_set(&light, 1.0f, 1.0f, 1.0f);
	// win.light = init_light(vec3(100.0, 0.0, 500), 0.9f, light);

	char *path = "/Users/jisokim2/MySubjects/minirt/file/.rt";
	if (!is_valid_file(path))
		return (-1);
	int fd = open_file(path);
	
	int check_read = read_file(fd, &win);
	printf("check_read %d\n", check_read);
	if (check_read == -1)
	{
		printf("failed parsing\n");
	}

	if (!win.mlx)
		error_window(&win);
	win.image = mlx_new_image(win.mlx, \
		(int32_t)screen.x, (int32_t)(screen.y));
	image_hook(&win);
	if (!win.image || (mlx_image_to_window(win.mlx, win.image, 0, 0) < 0))
		error_window(&win);
	
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	if (mlx_loop_hook(win.mlx, image_hook, &win) == false)
		error_window(&win);
	mlx_key_hook(win.mlx, ft_key_hook, &win);
	mlx_loop(win.mlx);

	mlx_terminate(win.mlx);

	
	free_objs_list(&win.objs);
	return (0);
}

//*********************************************parsing*************************************************
