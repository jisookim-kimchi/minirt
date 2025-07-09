#include "loadresource.h"

t_transform *get_local_transform_comp(t_transform_comp *transform)
{
    return (transform->local_transform);
}

t_transform *get_world_transform(t_transform_comp *transform)
{
    return (transform->world_transform);
}

t_vec3  get_world_position(t_transform_comp *transform)
{
    return (transform->world_transform->position);
}

// t_rotator get_world_rotator(t_transform_comp *transform)
// {
//     return (to_rotator(transform->world_transform->rotation));
// }

