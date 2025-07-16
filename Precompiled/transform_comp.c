#include "loadresource.h"

//need to make init transform_comp.c
/*
	at scene passer we need to set appropriated rocation of objects 
*/
t_transform_comp init_transform_comp(void)
{
	t_transform_comp transform_comp;
    transform_comp.transform = malloc(sizeof(t_transform));

	// //todo we should have value for position form parameters
    transform_comp.transform->position = vec3(0, 0, 0);
    transform_comp.transform->rotation = init_quaternion();
    transform_comp.transform->scale = vec3(1, 1, 1);
	transform_comp.forward = vec3(0, 0, 1);
	transform_comp.up = vec3(0, 1, 0);
	transform_comp.right = vec3(1, 0, 0);

	// transform_comp.pos = transform_comp.transform->position;
	return (transform_comp);
}

void set_transform_comp_position(t_transform_comp *comp, t_vec3 pos)
{
    comp->transform->position = pos;
}

void add_transform_comp_position(t_transform_comp *comp, t_vec3 delta)
{
    comp->transform->position = vec3_plus_vec3(comp->transform->position, delta);
}

t_transform *get_world_transform(t_transform_comp *transform_comp)
{
    return (transform_comp->transform);
}

t_vec3  get_world_position(t_transform_comp *transform_comp)
{
    return (transform_comp->transform->position);
}

t_vec3 get_forward_vector(t_transform_comp transform_comp)
{
    return transform_comp.forward;
}

t_vec3 get_right_vector(t_transform_comp transform_comp)
{
    return transform_comp.right;
}

t_vec3 get_up_vector(t_transform_comp transform_comp)
{
    return transform_comp.up;
}


// t_rotator get_world_rotator(t_transform_comp *transform)
// {
//     return (to_rotator(transform->world_transform->rotation));
// }

