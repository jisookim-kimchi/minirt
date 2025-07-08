#include "mathheader.h"

void    init_transform(const t_vec3 *vec3, t_transform *out)
{
    out->position.x = vec3->x;
    out->position.y = vec3->y;
    out->position.z = vec3->z;
}

