#include "../math/mathheader.h"
#include "loadresource.h"

typedef struct s_plane
{
    t_vec3  normal;
    float   d;
}   t_plane;

/*
    init plane 
*/
static inline t_plane plane_init(const t_vec3* normal, float d)
{
    if (fabs(vec3_length((*normal)) - 1.f) > 0.0001f)
    {
        perror("for plane normal vector must be a unit vector\n");
        exit(0);
    }
    t_plane p = {*normal, d};
    return p;
}