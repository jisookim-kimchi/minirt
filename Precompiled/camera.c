#include "loadresource.h"

t_camera    init_camera(t_screenpoint screen, t_transform_comp transform_comp)
{
    t_camera camera;
    camera.transform_comp = transform_comp;
    camera.viewportsize = screen;
    camera.fov = 60.f;
    // camera.far_clip = 5000.f;
    // camera.near_clip = 5.f;

    float theta = deg2rad(camera.fov);
    float half_of_fov = theta / 2.f;
    float focal_length = 1 / tanf(half_of_fov);

    camera.viewportsize.y = 2.f * tanf(half_of_fov);
    camera.viewportsize.x = camera.viewportsize.y * camera.viewportsize.aspect_ratio;
    
    camera.horizontal = vec3(camera.viewportsize.x, 0, 0);
    camera.vertical = vec3(0, camera.viewportsize.y, 0);

	//camera pos
	t_vec3 camera_position =  get_world_position(&camera.transform_comp);
	
	t_vec3 forward = get_forward_vector(transform_comp);
	t_vec3 center = vec3_plus_vec3(camera_position, vec3_multiply(forward, focal_length));
	
	t_vec3 half_horizontal = vec3_multiply(camera.horizontal, 0.5);
	t_vec3 half_vertical = vec3_multiply(camera.vertical, 0.5);
	camera.left_bottom = vec3_sub_vec3(center, half_horizontal);
	camera.left_bottom = vec3_sub_vec3(camera.left_bottom, half_vertical);
    return (camera);
}

struct s_transform_comp get_transform_comp(t_camera *camera)
{
    return (camera->transform_comp);
}

//field of view 
float   get_fov (const t_camera *camera)
{
    return camera->fov;
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
void    set_look_at_rotation_obj(t_camera *camera, const t_game_object *in_game_obj, const t_vec3 *in_up)
{
   
}

//rotate to target.
/*

*/
void    set_look_at_rotation_vec3(t_camera *camera, const t_vec3 in_target_position, const t_vec3 in_up)
{


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

// void    set_look_at_rotation_vec3(t_camera *camera, const t_vec3 in_target_position, const t_vec3 in_up)
// {
//     t_vec3  local_x;
//     t_vec3  local_y;
//     t_vec3  local_z;

//     local_z = vec3_sub_vec3(in_target_position, camera->transform_comp.world_transform->position);
//     local_z = vec3_normalized(local_z);

//     if(fabs(local_z.y) >= (1.f - 1e-8))
//     {
//         local_x = vec3(1.f, 0.f, 0.f);
//     }
//     else
//     {
//         local_x = vec3_cross(in_up, local_z);
//         local_x = vec3_normalized(local_x);
//     }
//     local_y = vec3_cross(local_z, local_x);

//     camera->transform_comp.up = local_y;
//     camera->transform_comp.right = local_x;
//     camera->transform_comp.forward = local_z;
// }



// float   get_far_clip(const t_camera *camera)
// {
//     return camera->far_clip;
// }

// float   get_near_clip(const t_camera *camera)
// {
//     return camera->near_clip;
// }

// void    set_near_clip(t_camera *camera, float in_near_clip)
// {
//     camera->near_clip = in_near_clip;
// }

// void    set_far_clip(t_camera *camera, float in_far_clip)
// {
//     camera->far_clip = in_far_clip;
// }