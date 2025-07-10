#include "loadresource.h"

// t_camera    init_camera(t_screenpoint screen, t_vec3 vec3)
// {
//     t_camera camera;
//     camera.transform.position = 
// }

struct s_transform_comp *get_transform(t_camera *camera)
{
    return &(camera->transform_comp);
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
void    set_look_at_rotation_obj(t_camera *camera, const t_game_object *in_game_obj, const t_vec3 *in_up)
{
   
}

//rotate to target.
/*
    
*/
void    set_look_at_rotation_vec3(t_camera *camera, const t_vec3 in_target_position, const t_vec3 in_up)
{
    t_vec3  local_x;
    t_vec3  local_y;
    t_vec3  local_z;

    local_z = vec3_sub_vec3(in_target_position, camera->transform_comp.world_transform->position);
    local_z = vec3_normalized(local_z);

    if(fabs(local_z.y) >= (1.f - 1e-8))
    {
        local_x = vec3(1.f, 0.f, 0.f);
    }
    else
    {
        local_x = vec3_cross(in_up, local_z);
        local_x = vec3_normalized(local_x);
    }
    local_y = vec3_cross(local_z, local_x);

    camera->transform_comp.up = local_y;
    camera->transform_comp.right = local_x;
    camera->transform_comp.forward = local_z;
}

//

