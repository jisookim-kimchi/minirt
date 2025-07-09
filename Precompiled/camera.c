#include "loadresource.h"

t_camera    camera(t_screenpoint screen, t_vec3 vec3)
{
    t_camera camera;
    float 
}

struct s_transform *get_transform(t_camera *camera)
{
    return &(camera->transform);
}

//field of view 
float   get_fov (const t_camera *camera)
{
    return camera->fov;
}

float   get_far_clip(const t_camera *camera)
{
    return camera->far_clip;
}

float   get_near_clip(const t_camera *camera)
{
    return camera->near_clip;
}

/*
    change modeling matrix to view matrix
    modeling matrix ?? : local - >world
    view matrix : world -> camera
*/

// void    get_view_axes(t_vec3 *outview_x, const t_vec3 *outview_y, const t_vec3 *outview_z)
// {
//     outview_x = -getlocal_x()
//     outview_y = getlocal_y()
//     outview_z = -getlocal_z();
// }

/*
    get view axes
*/

// t_matrix_4x4    get_view_matrix(t_transform_comp * transform)
// {
//     t_vec3  view_x;
//     t_vec3  view_y;
//     t_vec3  view_z;

//     get_view_axes(view_x, view_y, view_z);
//     t_vec3  pos = get_world_position(transform);

//     return t_matrix_4x4
//     (
//         t_vec4(t_vec3(),)
//         t_vec4(t_vec3(),)
//         t_vec4(t_vec3(),)
//         t_vec4(view_x)
//     )
// }

struct s_screenpoint *get_viewport_size(const t_camera *camera)
{
    return &(camera->viewportsize);
}

void    setfov(float infov, t_camera *camera)
{
    camera->fov = infov;
}

//rotate to game_obj.
void    set_look_at_rotation_obj(const t_game_object *in_game_obj, const t_vec3 *in_up)
{
    
}

//rotate to target.
void    set_look_at_rotation_vec3(const t_vec3 target, const t_vec3 *in_up)
{
    
}

//

