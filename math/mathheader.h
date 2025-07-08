#include "vector_struct.h"

typedef struct s_transform
{
    t_vec3          position;
    t_quaternion    rotation;
    t_vec3          scale;
}   t_transform;

typedef struct s_quaternion
{
    float   x;
    float   y;
    float   z;
    float   w;
} t_quaternion;