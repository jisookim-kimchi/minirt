#include "loadresource.h"

/*
    Get camera orientation to set the horizontal and vertical values of the screen
    camera->horizontal : horizontal vector.
	camera->vertical : vertical vector.
	camera->delta_horizontal or vertical =  The 3D directional vector change when moving one pixel to the right or down .
    camera->delta_vertical = vec3_divide(camera->vertical, (double)IMAGE_HEIGHT);
    TODO:
    Need to check if get_right_vector and get_up vector is correct
*/
static void camera_orientation(t_camera *camera)
{
    t_vec3  right;
    t_vec3  up;

    right = get_right_vector(camera->transform_comp);
    up = get_up_vector(camera->transform_comp);
    camera->horizontal = vec3_multiply(right, camera->viewport_w);
    camera->vertical = vec3_multiply(up, -camera->viewport_h);
    camera->delta_horizontal = vec3_divide(camera->horizontal, (double)IMAGE_WIDTH);
    camera->delta_vertical = vec3_divide(camera->vertical, (double)IMAGE_HEIGHT);
}

/*
    The calculate_pixel00loc is a helper function to execute 
    the pixel00loc value. This does the following steps:
    sum_delta_hv = add delta_horizontal vector to the delta_vertical vector
    half_sum_delta_hv = sum_delta_hv divided by 2
    camera->pixel00loc = add camera->left_bottom vector to 
                        half_sum_delta_hv vector
*/
static void calculate_pixel00loc(t_camera *camera)
{
    t_vec3  sum_delta_hv;
    t_vec3  half_sum_delta_hv;

    sum_delta_hv = vec3_plus_vec3(camera->delta_horizontal, camera->delta_vertical);
    half_sum_delta_hv = vec3_divide(sum_delta_hv, 2.0);
    camera->pixel00loc = vec3_plus_vec3(camera->left_bottom, half_sum_delta_hv);
}

/*
    We need to consider how we want to pass the information 
    about mlx image_width and image_height size. Currently 
    it use the mlx_tools.h IMAGE_WIDTH and IMAGE_RATIO values
*/

t_camera    init_camera(t_screenpoint screen, t_transform_comp transform_comp)
{
    t_camera camera;
    t_vec3 forward;
    camera.transform_comp = transform_comp;
    // camera.viewportsize = screen;

    camera.fov = 60.f;
    float theta = deg2rad(camera.fov);
    float half_of_fov = theta / 2.f;
    camera.focal_length = 1 / tanf(half_of_fov);
    camera.viewport_h = 2.f * tanf(half_of_fov);
    camera.viewport_w = camera.viewport_h * screen.aspect_ratio;
	
	//camera pos
	t_vec3 camera_position =  get_world_position(&camera.transform_comp);

    camera_orientation(&camera);
	// t_vec3 forward = (t_vec3){0,0,-1};
    forward = vec3_multiply(get_forward_vector(camera.transform_comp), -1.0);
	
	t_vec3 center = vec3_plus_vec3(camera_position, vec3_multiply(forward, camera.focal_length));
	t_vec3 half_horizontal = vec3_multiply(camera.horizontal, 0.5);
	t_vec3 half_vertical = vec3_multiply(camera.vertical, 0.5);
	camera.left_bottom = vec3_sub_vec3(center, half_horizontal);
	camera.left_bottom = vec3_sub_vec3(camera.left_bottom, half_vertical);
	// printf(CYAN);
	// printf("camera focal_len %f\n", focal_length);
	// printf("screen.x : %d , screen.y : %d\n",screen.x, screen.y);
	// printf("viewportsize.y : %f , viewportsize.x : %f, screen ratio : %f\n", camera.viewport_h, camera.viewport_w , screen.aspect_ratio);
	// printf("camera horizontal vector x : %f, y :%f, z :%f\n", camera.horizontal.x,camera.horizontal.y, camera.horizontal.z);
	// printf("camera vertical vector x : %f, y :%f, z :%f\n", camera.vertical.x,camera.vertical.y, camera.vertical.z);
	// printf("camera.left_bottom.x : %f , y: %f , z :%f\n", camera.left_bottom.x, camera.left_bottom.y, camera.left_bottom.z);
	// printf("camera->delta_horizontal.x : %f, y : %f, z : %f\n", camera.delta_horizontal.x, camera.delta_horizontal.y, camera.delta_horizontal.z);
	// printf("camera->delta_vertical.x : %f, y : %f, z : %f\n", camera.delta_vertical.x, camera.delta_vertical.y, camera.delta_vertical.z);
	// printf(DEFAULT);
    calculate_pixel00loc(&camera);
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

// struct const s_screenpoint *get_viewport_size(const t_camera *camera)
// {
//     return (&(camera->viewportsize));
// }

void    setfov(float infov, t_camera *camera)
{
    camera->fov = infov;
}


/*
    TODO
    it need implement later.
//rotate to game_obj.
void    set_look_at_rotation_obj(t_camera *camera, const t_game_object *in_game_obj, const t_vec3 *in_up)
{
   
}

//rotate to target.


void    set_look_at_rotation_vec3(t_camera *camera, const t_vec3 in_target_position, const t_vec3 in_up)
{
    

}

*/
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
