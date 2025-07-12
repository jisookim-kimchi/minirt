#include "loadresource.h"

//need to make init transform_comp.c
t_transform_comp init_transform_comp()
{
	t_transform_comp transform_comp;

	return (transform_comp);
}

t_transform *get_world_transform(t_transform_comp *transform_comp)
{
    return (transform_comp->transform);
}

t_vec3  get_world_position(t_transform_comp *transform_comp)
{
    return (transform_comp->transform->position);
}

// t_rotator get_world_rotator(t_transform_comp *transform)
// {
//     return (to_rotator(transform->world_transform->rotation));
// }

