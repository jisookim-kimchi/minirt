
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "vector_struct.h"
#include "../math/mathheader.h"

//#include <vector2.h>
//#include <vector3.h>

#define MAX_MESHES 100
#define MAX_TEXTURES 100
#define MAX_SCENE_OBJECTS 100

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

typedef struct s_transform_comp
{
    t_vec3 right;
    t_vec3 up;
    t_vec3 forward;
    //t_transform *local_transform;
	t_vec3 pos;
    t_transform *transform;
}   t_transform_comp;

/*
    fov : field of view
    far_clip : Distance from the camera to the far clipping plane
    far_clip : Distance from the camera to the near clipping plane
*/
typedef struct s_camera
{
    t_transform_comp    transform_comp;
    t_screenpoint       viewportsize;
    float               fov;
    // float               far_clip;
    // float               near_clip;
    t_vec3              horizontal;
    t_vec3              vertical;
    t_vec3              left_bottom;
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




//transform_comp.c
t_vec3  get_world_position(t_transform_comp *transform_comp);