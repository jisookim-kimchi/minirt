#include "loadresource.h"

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

void    get_view_axes(t_vec3 *outview_x, t_vec3 *outview_y, t_vec3 *outview_z, const t_camera *camera)
{
    
}