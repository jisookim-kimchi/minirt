#include "vector_struct.h"
#include <math.h>

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

typedef struct s_rotator
{
    float yaw;
    float roll;
    float pitch;
} t_rotator;

t_quaternion init_quaternion();