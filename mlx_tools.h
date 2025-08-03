/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tools.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 18:43:53 by tfarkas           #+#    #+#             */
/*   Updated: 2025/08/03 16:49:07 by jisokim2         ###   ########.fr       */
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

void			get_ray_from_camera(t_camera *camera, t_ray *ray,
					uint32_t x, uint32_t y);
void		color_transform_to_int(t_color_float *col_float, t_color_32 *col_32);
void		pixel_center_color(t_ray *ray, t_window *win, t_color_32 *result_color);
t_color_float	calculate_hit_color(t_window *win, t_hit *hit);


//The init_objects.c file consist helper function to allocate objects
t_objs_list	*init_objs_list(void);

#endif