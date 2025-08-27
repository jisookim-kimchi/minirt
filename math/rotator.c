#include "mathheader.h"

/*
    pitch = x.
    yaw = y.
    roll = z.
*/
t_rotator init_rotator()
{
    t_rotator rotator;

    rotator.pitch = 0.f;
    rotator.yaw = 0.f;
    rotator.roll = 0.f;

    return (rotator);
}

t_rotator constructor( float in_yaw, float in_pitch, float in_roll)
{
    t_rotator rotator;

    rotator.yaw = in_yaw;
    rotator.pitch = in_pitch;
    rotator.roll = in_roll;

    return(rotator);
}

/*
    fmodf : returns the floating-point remainder of x / y.
    if angle is -450.f  -> −450−(−1×360)
    angle = -90
    -90 + 360 = 270.
*/

float clamp_axis(float angle)
{
    angle = fmodf(angle, 360.0f);
    if (angle < 0.0f)
        angle += 360.0f;
    return (angle);
}

void clamp(t_rotator *rotator)
{
    if (!rotator)
        return;
    
    rotator->yaw   = clamp_axis(rotator->yaw);
    rotator->roll  = clamp_axis(rotator->roll);
    rotator->pitch = clamp_axis(rotator->pitch);
}

// from Euler'angle to local_axes
/*
    when a obj rotate, update new axes 
*/
void get_local_axes(const t_rotator* rot, t_vec3* outRight, t_vec3* outUp, t_vec3* outForward)
{
    float sy = sinf(rot->yaw);
    float cy = cosf(rot->yaw);
    float sp = sinf(rot->pitch);
    float cp = cosf(rot->pitch);
    float sr = sinf(rot->roll);
    float cr = cosf(rot->roll);

    outRight->x = cy * cr + sy * sp * sr;
    outRight->y = cp * sr;
    outRight->z = -sy * cr + cy * sp * sr;

    outUp->x = -cy * sr + sy * sp * cr;
    outUp->y = cp * cr;
    outUp->z = sy * sr + cy * sp * cr;

    outForward->x = sy * cp;
    outForward->y = -sp;
    outForward->z = cy * cp;
}
