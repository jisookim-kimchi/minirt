/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tools.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 18:43:53 by tfarkas           #+#    #+#             */
/*   Updated: 2025/07/20 21:38:44 by tfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_TOOLS_H
# define MLX_TOOLS_H

// # include "MLX42/include/MLX42/MLX42.h"
// # include "Precompiled/loadresource.h"
# include "object/objects.h"
# include "debug/debug.h"
# include "lighting/lighting.h"

typedef struct s_window
{
	t_camera		camera;
	// t_color_float	ambient;
	t_ambient		ambient;
	t_light			light;
	t_objs_list		*objs;
	mlx_t			*mlx;
	mlx_image_t		*image;
}	t_window;

void		get_ray_from_camera(t_camera *camera, t_ray *ray,
				uint32_t x, uint32_t y);
t_color_32	color_transform_to_int(t_color_float *col_float);
t_color_32	pixel_center_color(t_ray *ray, t_window *win);


//The init_objects.c file consist helper function to allocate objects
t_objs_list	*init_objs_list(void);

#endif