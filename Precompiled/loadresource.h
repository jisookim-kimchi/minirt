/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadresource.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 14:36:41 by jisokim2          #+#    #+#             */
/*   Updated: 2025/08/30 16:14:47 by jisokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOADRESOURCE_H
# define LOADRESOURCE_H

# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include "../math/mathheader.h"
# include <fcntl.h>
# include <assert.h>
# include <stdbool.h>

# define MAX_MESHES 100
# define MAX_TEXTURES 100
# define MAX_SCENE_OBJECTS 100

# define IMAGE_WIDTH 1200
# define IMAGE_HEIGHT 800

# define RED        "\033[1;31m"
# define BLACK      "\033[1;30m"
# define RED        "\033[1;31m"
# define GREEN      "\033[1;32m"
# define YELLOW     "\033[1;33m"
# define BLUE       "\033[1;34m"
# define MAGENTA    "\033[1;35m"
# define CYAN       "\033[1;36m"
# define WHITE      "\033[1;37m"
# define DEFAULT    "\033[0m"

typedef struct s_transform_comp
{
	t_vec3		right;
	t_vec3		up;
	t_vec3		forward;
	t_transform	transform;
}	t_transform_comp;

typedef struct s_camera
{
	t_transform_comp	transform_comp;
	float				viewport_h;
	float				viewport_w;
	float				fov;
	float				focal_length;
	t_vec3				horizontal;
	t_vec3				vertical;
	t_vec3				delta_horizontal;
	t_vec3				delta_vertical;
	t_vec3				left_bottom;
	t_vec3				pixel00loc;
}	t_camera;

//camera.c
t_camera			init_camera(t_screenpoint screen,
						t_transform_comp transform_comp);

//transform_comp_helper.c
t_vec3				get_world_position(t_transform_comp *transform_comp);
t_vec3				get_right_vector(t_transform_comp transform_comp);
t_vec3				get_up_vector(t_transform_comp transform_comp);

//transform_comp.c
t_vec3				get_forward_vector(t_transform_comp transform_comp);
t_transform_comp	init_transform_comp(void);
void				set_transform_comp_position(t_transform_comp *comp,
						t_vec3 pos);
void				add_transform_comp_position(t_transform_comp *comp,
						t_vec3 delta);

#endif