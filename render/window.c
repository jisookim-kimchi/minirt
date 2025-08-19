/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 18:47:54 by tfarkas           #+#    #+#             */
/*   Updated: 2025/08/18 15:05:31 by jisokim2         ###   ########.fr       */
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
			pixel_center_color(&ray_pixel_center, win, &pixel_center_col);
			mlx_put_pixel(win->image, x, y, pixel_center_col.result_color);
			x++;
		}
		y++;
	}
}

int main(void)
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
	//win.objs = init_objs_list();

	/* parsing start */
	char *path = "file/.justplane.rt";
	if (!is_valid_file(path))
		return (-1);
	int fd = open_file(path);
	int check_read = read_file(fd, &win);
	//printf("check_read %d\n", check_read);
	if (check_read < 0)
	{
		free_objs_list(&win.objs);
		printf("failed parsing\n");
		exit(1);
	}
	win.spot_light = init_spot_light(&win.light, (t_vec3){0,1,-1}, 100.0, 45.0, 1.0);

	// t_plane *temp;
	// temp = win.objs->data;
	// printf(CYAN"temp unit_norm_vec %f, %f, %f\n", temp->unit_normal_vec.x, temp->unit_normal_vec.y, temp->unit_normal_vec.z);
	// printf("temp point %f, %f, %f\n", temp->point.x, temp->point.y, temp->point.z);
	// printf("temp color %f, %f, %f\n"DEFAULT, temp->plane_color.red, temp->plane_color.green, temp->plane_color.blue);
	// printf("win.light %f, %f, %f\n", win.light.light_position.x, win.light.light_position.y, win.light.light_position.z);
	// printf("Camera position: (%f, %f, %f)\n", win.camera.transform_comp.transform->position.x, win.camera.transform_comp.transform->position.y, win.camera.transform_comp.transform->position.z);
	// printf("Pixel00 location: (%f, %f, %f)\n", win.camera.pixel00loc.x, win.camera.pixel00loc.y, win.camera.pixel00loc.z);
	// printf("Delta horizontal: (%f, %f, %f)\n", win.camera.delta_horizontal.x, win.camera.delta_horizontal.y, win.camera.delta_horizontal.z);
	// printf("Delta vertical: (%f, %f, %f)\n", win.camera.delta_vertical.x, win.camera.delta_vertical.y, win.camera.delta_vertical.z);
	
	// t_objs_list *test = win.objs;
	// while(test)
	// {
	// 	if (test->obj_type == PLANE)
	// 	{
	// 		printf("PLANE\n");
	// 		t_plane *plane = test->data;
	// 		printf("PLANE pos : %f, %f, %f\n", plane->point.x, plane->point.y, plane->point.z);
	// 	}
	// 	else if (test->obj_type == CYLINDER)
	// 		printf("cylinder\n");
	// 	else if (test->obj_type == SPHERE)
	// 	{
	// 		printf("SPHERE\n");
	// 		t_sphere *sphere = test->data;
	// 		printf("SPHERE pos : %f, %f, %f\n", sphere->center.x, sphere->center.y, sphere->center.z);
	// 	}
	// 	test = test->next;
	// }
	win.mlx = mlx_init(IMAGE_WIDTH, IMAGE_WIDTH / IMAGE_RATIO, "Practice", true);
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
