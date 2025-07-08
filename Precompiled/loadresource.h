#include <math.h>
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

typedef struct s_camera
{

} t_camera;

//it must have transform_component;
typedef struct s_game_object
{
    char    name[64];
    //size_t  hash;
    //int     mash_key;
    t_transform tramsform;
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


