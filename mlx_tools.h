/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tools.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 18:43:53 by tfarkas           #+#    #+#             */
/*   Updated: 2025/07/14 19:55:38 by tfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_TOOLS_H
# define MLX_TOOLS_H

# include "MLX42/include/MLX42/MLX42.h"
# include "../Precompiled/loadresource.h"
# include "libft/libft.h"
# include <stdio.h>
# include <stdbool.h>

# define IMAGE_WIDTH 1200
# define IMAGE_RATIO (16.0f/9.0f)

typedef struct s_color_float
{
	float	red;
	float	green;
	float	blue;
}	t_color_float

typedef struct s_color_32
{
	uint32_t	red;
	uint32_t	green;
	uint32_t	blue;
	uint32_t	alpha;
	uint32_t	result_color;
}	t_color_32;

typedef struct s_window
{
	t_camera	camera;
	t_objs_list	objs;
	t_color_32	ambient;
	mlx_t		*mlx;
	mlx_image_t	*image;
}	t_window;

float		clamp_calculation(float input_value, float min, float max);
bool		check_value_in_range(float input_value, float min, float max);
void		get_ray_from_camera(t_camera *camera, t_ray *ray,
				uint32_t x, uint32_t y);
t_color_32	color_transform_to_int(t_color_float *col_float);
t_color_32	pixel_center_color(t_ray *ray);

#endif