/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 18:40:58 by tfarkas           #+#    #+#             */
/*   Updated: 2025/08/30 12:02:40 by tfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../parser/parser.h"
#include "../mlx_tools.h"

/*
	The camera moves position can check with the following function:
		print_camera_infos(&win->camera); 
*/
static void	camera_movements_keys(mlx_key_data_t *keydata, t_window *win)
{
	double		delta_move;

	delta_move = 0.05;
	if (keydata->key == MLX_KEY_W && keydata->action == MLX_PRESS)
		add_transform_comp_position(&win->camera.transform_comp,
			vec3(0, -1.0 * delta_move, 0));
	if (keydata->key == MLX_KEY_S && keydata->action == MLX_PRESS)
		add_transform_comp_position(&win->camera.transform_comp,
			vec3(0, delta_move, 0));
	if (keydata->key == MLX_KEY_D && keydata->action == MLX_PRESS)
		add_transform_comp_position(&win->camera.transform_comp,
			vec3(-1.0 * delta_move, 0, 0));
	if (keydata->key == MLX_KEY_A && keydata->action == MLX_PRESS)
		add_transform_comp_position(&win->camera.transform_comp,
			vec3(delta_move, 0, 0));
	if (keydata->key == MLX_KEY_R && keydata->action == MLX_PRESS)
		set_transform_comp_position(&win->camera.transform_comp, vec3(0, 0, 0));
	if (keydata->key == MLX_KEY_UP && keydata->action == MLX_PRESS)
		add_transform_comp_position(&win->camera.transform_comp,
			vec3(0, 0, delta_move));
	if (keydata->key == MLX_KEY_DOWN && keydata->action == MLX_PRESS)
		add_transform_comp_position(&win->camera.transform_comp,
			vec3(0, 0, -1.0 * delta_move));
}

void	ft_key_hook(mlx_key_data_t keydata, void *param)
{
	t_window	*win;

	win = (t_window *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(win->mlx);
	if (keydata.key == MLX_KEY_O && keydata.action == MLX_PRESS)
		win->antialisign.antialisign_on = true;
	if (keydata.key == MLX_KEY_P && keydata.action == MLX_PRESS)
		win->antialisign.antialisign_on = false;
	camera_movements_keys(&keydata, win);
}

void	antialisign_message(t_window *win)
{
	if (win->antialisign.antialisign_text)
	{
		mlx_delete_image(win->mlx, win->antialisign.antialisign_text);
		win->antialisign.antialisign_text = NULL;
	}
	if (win->antialisign.antialisign_on == true)
	{
		win->antialisign.antialisign_text
			= mlx_put_string(win->mlx, "Antialiasign: ON", 5, 5);
	}
	else
	{
		win->antialisign.antialisign_text
			= mlx_put_string(win->mlx, "Antialiasign: OFF", 5, 5);
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

	If we want to use the program without antialisign the switch_antialisign
	function need to be replace the following two lines:
		get_ray_from_camera(&win->camera, &ray_pixel_center, x, y);
		pixel_center_color(&ray_pixel_center, win, &pixel_center_col);
*/
void	image_hook(void *param)
{
	t_window	*win;
	t_color_32	pixel_center_col;

	win = (t_window *)param;
	win->antialisign.y = 0;
	while (win->antialisign.y < win->image->height)
	{
		win->antialisign.x = 0;
		while (win->antialisign.x < win->image->width)
		{
			switch_antialisgn(win, &pixel_center_col);
			mlx_put_pixel(win->image, win->antialisign.x,
				win->antialisign.y, pixel_center_col.result_color);
			win->antialisign.x++;
		}
		win->antialisign.y++;
	}
	antialisign_message(win);
}
