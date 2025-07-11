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

/*
    aspectratio = x / y
*/
typedef struct s_screenpoint
{
    int     x;
    int     y;
    float   aspect_ratio;
} t_screenpoint;

t_quaternion init_quaternion();

//rotator.c
t_rotator init_rotator();
t_rotator constructor( float in_yaw, float in_pitch, float in_roll);
float clamp_axis(float angle);
void clamp(t_rotator *rotator);
void get_local_axes(const t_rotator* rot, t_vec3* outRight, t_vec3* outUp, t_vec3* outForward);


//mathutils.c
float deg2rad(float indegree);