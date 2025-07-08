/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tools.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfarkas <tfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 18:43:53 by tfarkas           #+#    #+#             */
/*   Updated: 2025/07/08 11:44:21 by tfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_TOOLS_H
# define MLX_TOOLS_H

# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
# include <stdbool.h>

# define IMAGE_WIDTH 1200
# define IMAGE_RATIO 16/9

typedef struct s_window
{
	mlx_t		*mlx;
	mlx_image_t	*image;
}	t_window;

#endif