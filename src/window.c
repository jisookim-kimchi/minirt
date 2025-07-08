/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 18:47:54 by tfarkas           #+#    #+#             */
/*   Updated: 2025/07/08 11:43:25 by tfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_tools.h"

void	error_window(t_window *win)
{
	ft_putendl_fd((char *)mlx_strerror(mlx_errno), 2);
	if (win->mlx)
		mlx_terminate(win->mlx);
}

/*
	The color layout: 0xAARRGGBB
	AA = Alpha (opacity)
	RR = Red
	GG = Green
	BB = Blue 
*/
void	image_hook(void *param)
{
	t_window	*win;
	uint32_t	x;
	uint32_t	y;
	uint32_t	blue;

	blue = 0xFF0000FF;
	win = (t_window *)param;
	y = 0;
	while (y < win->image->height)
	{
		x = 0;
		while (x < win->image->width)
		{
			mlx_put_pixel(win->image, x, y, blue);
			x++;
		}
		y++;
	}
	
}

int main(void)
{
	t_window	win;

	win.mlx = mlx_init(IMAGE_WIDTH, IMAGE_WIDTH / IMAGE_RATIO, "Practice", true);
	if (!win.mlx)
		error_window(&win);
	win.image = mlx_new_image(win.mlx, \
		(int32_t)IMAGE_WIDTH, (int32_t)(IMAGE_WIDTH / IMAGE_RATIO));
	if (!win.image || (mlx_image_to_window(win.mlx, win.image, 0, 0) < 0))
		error_window(&win);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	if (mlx_loop_hook(win.mlx, image_hook, &win) == false)
		error_window(&win);
	mlx_loop(win.mlx);
	mlx_terminate(win.mlx);
	return (0);
}