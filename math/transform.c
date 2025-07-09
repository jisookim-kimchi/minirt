#include "mathheader.h"
#include "../vector_struct.h"

t_transform make_transform_pos(const t_vec3* position)
{
    t_transform t;
    
    t.position = *position;
    t.rotation = init_quaternion();
    t.scale = vec3_one();
    
    return (t);
}

t_transform make_transform_rot(const t_quaternion *in_rot, const t_vec3 *in_pos)
{
    t_transform t;

    t.position = *in_pos;
    t.rotation = *in_rot;
    t.scale = vec3_one();

    return t;
}

t_transform make_transform_pos_rot_scale(const t_vec3* pos, const t_quaternion* rot, const t_vec3* scale)
{
    t_transform t;

    t.position = *pos;
    t.rotation = *rot;
    t.scale = *scale;

    return t;
}

void    add_position(t_transform *transform, t_vec3 *in_deltapos)
{
    vec3_plus_vec3(transform->position, *in_deltapos);
}

void    set_position(t_transform *transform, t_vec3 *in_pos)
{
    transform->position.x = in_pos->x;
    transform->position.y = in_pos->y;
    transform->position.z = in_pos->z;
}

//transformation in 3d world
// t_transform transform(const Matrix4x4& InMatrix)
// {

// }

/*
    quaternion -> rotation.

    rotation -> quaternion.
*/

void    add_yaw_rot(float in_degree)
{
    t_transform transform;
    t_rotator r = transform.rotation.to_ratator();
    r.yaw += in_degree;
    r.clamp();

    transform.rotation = quaternion(r);
}