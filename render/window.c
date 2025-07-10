/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 18:47:54 by tfarkas           #+#    #+#             */
/*   Updated: 2025/07/10 13:32:44 by tfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_tools.h"

/*
	The clamp_calculation function not allow the input value will 
	be bigger or smaller than the given intervallum. If the input value smaller, 
	it returns the min value, if bigger, return the max value.
*/
float	clamp_calculation(float input_value, float min, float max)
{
	if (input_value <= min)
		return (min);
	if (input_value >= max)
		return (max);
	return (input_value);
}

/*
	The color_transform_to_int funtion change the color 
	float value  (which should be in the range 0.0 and 1.0)
	into uint_32 format which the renderer can use
*/
t_color_32	color_transform_to_int(t_color_float *col_float)
{
	t_color_32	col_32;

	col_32.red = (uint32_t)(255.999
			* clamp_calculation(col_float->red, 0.0f, 1.0f));
	col_32.green = (uint32_t)(255.999
			* clamp_calculation(col_float->green, 0.0f, 1.0f));
	col_32.blue = (uint32_t)(255.999
			* clamp_calculation(col_float->blue, 0.0f, 1.0f));
	col_32.alpha = 255;
	col_32.result_color = (col_32.red << 24) | (col_32.green << 16)
		| (col_32.blue << 8) | (col_32.alpha);
	return (col_32);
}

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
	The color layout: 0xRRGGBBAA
	RR = Red
	GG = Green
	BB = Blue
	AA = Alpha (opacity)
*/
void	image_hook(void *param)
{
	t_window	*win;
	uint32_t	x;
	uint32_t	y;
	uint32_t	blue;

	blue = 0x0000FFFF;
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
		
	// printf("The image width: %d\nThe image height: %d\n", win.image->width, win.image->height);
	// printf("The value IMAGE_WIDTH/IMAGE_RATIO: %f\n", (IMAGE_WIDTH / IMAGE_RATIO));
	// printf("The value IMAGE_RATIO: %f\n", IMAGE_RATIO);
	
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	if (mlx_loop_hook(win.mlx, image_hook, &win) == false)
		error_window(&win);
	mlx_key_hook(win.mlx, ft_key_hook, &win);
	mlx_loop(win.mlx);
	mlx_terminate(win.mlx);
	return (0);
}
