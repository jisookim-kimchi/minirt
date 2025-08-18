/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadresource.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 14:36:41 by jisokim2          #+#    #+#             */
/*   Updated: 2025/08/18 17:34:41 by jisokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOADRESOURCE_H
# define LOADRESOURCE_H

//todo add get_next_line
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include "../math/mathheader.h"
# include <fcntl.h>
# include <assert.h>
//# include <stdio.h>
# include <stdbool.h>

# define MAX_MESHES 100
# define MAX_TEXTURES 100
# define MAX_SCENE_OBJECTS 100

# define IMAGE_WIDTH 1200
# define IMAGE_HEIGHT 800
# define IMAGE_RATIO (16.0f/9.0f)

//Bold colors
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

typedef struct s_mesh
{
    t_vec2  vertices[4];
    int     vertex_count;
    int     indices[6];
    int     index_count;
    t_vec2  uvs[4];
}   t_mesh;

typedef struct s_texture
{
    char* path;
    int initialized;
} t_texture;

//todo maybe we dont need t_vec3 pos the transform pointer has it already
typedef struct s_transform_comp
{
    t_vec3 right;
    t_vec3 up;
    t_vec3 forward;
    //t_transform *local_transform;
	//t_vec3 pos;
    t_transform *transform;
}   t_transform_comp;

/*
    fov : field of view
    far_clip : Distance from the camera to the far clipping plane
    far_clip : Distance from the camera to the near clipping plane
	//todo maybe we dont need t_screenpoint struct in the camera struct.
*/
typedef struct s_camera
{
    t_transform_comp    transform_comp;
    //t_screenpoint       viewportsize;
	float				viewport_h;
	float				viewport_w;
    float               fov;
    // float               far_clip;
    // float               near_clip;
    t_vec3              horizontal;
    t_vec3              vertical;
    t_vec3              delta_horizontal;
    t_vec3              delta_vertical;
    t_vec3              left_bottom;
    t_vec3              pixel00loc;
} t_camera;

//it must have transform_component;
typedef struct s_game_object
{
    char    name[64];
    //size_t  hash;
    //int     mash_key;
    t_transform_comp transform_comp;
    //t_Linearcolor color;
    int     is_visible;
}   t_game_object;

//later it is better to add mlx* and mlx_image? 
typedef struct s_engine
{
    t_mesh          meshes[MAX_MESHES];
    int             mesh_count;
    t_texture       textures[MAX_TEXTURES];
    int             texture_count;
    t_game_object   scene[MAX_SCENE_OBJECTS];
    int             scene_count;
    t_camera        camera;
    //mlx_t         *mlx;
}   t_engine;

typedef struct s_parser
{
	char *id;
}	t_parser;

//camera.c
t_camera    init_camera(t_screenpoint screen, t_transform_comp transform_comp);

//transform_comp.c
t_vec3  get_world_position(t_transform_comp *transform_comp);
t_vec3 get_right_vector(t_transform_comp transform_comp);
t_vec3 get_up_vector(t_transform_comp transform_comp);
t_vec3 get_forward_vector(t_transform_comp transform_comp);
t_transform_comp init_transform_comp(void);

#endif