/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tools.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 18:43:53 by tfarkas           #+#    #+#             */
/*   Updated: 2025/08/30 13:45:16 by tfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_TOOLS_H
# define MLX_TOOLS_H

// # include "MLX42/include/MLX42/MLX42.h"
// # include "Precompiled/loadresource.h"
# include "object/objects.h"
# include "debug/debug.h"
# include "lighting/lighting.h"

typedef struct s_antialisign
{
	int			i;
	int			j;
	uint32_t	x;
	uint32_t	y;
	int			samples_num;
	bool		antialisign_on;
	mlx_image_t	*antialisign_text;
}	t_antialisign;

typedef struct s_window
{
	t_screenpoint	screen;
	t_camera		camera;
	t_ambient		ambient;
	t_light			light;
	t_spot_light	spot_light;
	t_antialisign	antialisign;
	t_objs_list		*objs;
	mlx_t			*mlx;
	mlx_image_t		*image;
}	t_window;

// main_utils.c
void			error_window(t_window *win);
char			*check_file_arg(int argc, char **argv);
void			init_window(t_window *win);

//color_calculation_utils.c
void			get_ray_from_camera(t_window *win, t_ray *ray);
void			color_transform_to_int(t_color_float *col_float,
					t_color_32 *col_32);

// pixel_color.c
void			pixel_center_color(t_ray *ray, t_window *win,
					t_color_32 *result_color);
t_color_float	calculate_hit_color(t_window *win, t_hit *hit);

//antialisign.c
t_color_float	pixel_sample_color(t_ray *ray, t_window *win);
t_ray			get_pixel_ray(t_window *window);
t_color_float	n_samples_in_pixel(t_window *win);
void			switch_antialisgn(t_window *win,
					t_color_32 *pixel_center_col);

//checkboard.c
t_color_float	checkboard_pattern(t_hit *hit);
void			checkboard_switch_on(t_window *win, t_hit *record);

// hooks.c
void			ft_key_hook(mlx_key_data_t keydata, void *param);
void			antialisign_message(t_window *win);
void			image_hook(void *param);

#endif