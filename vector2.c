#include "vector_struct.h"

typedef struct s_vec2 
{
    double x;
    double y;
} t_vec2;

t_vec2 vec2(double x, double y)
{
    t_vec2 vec;
    vec.x = x;
    vec.y = y;
    return vec;
}

void vec2_set(t_vec2 *vec2, double x, double y)
{
    vec2->x = x;
    vec2->y = y;
}

double vec2_length_squared(t_vec2 vec)
{
    return (vec.x * vec.x + vec.y * vec.y);
}

double vec2_length(t_vec2 vec)
{
    return sqrt(vec2_length_squared(vec));
}

t_vec2 vec2_add(t_vec2 vec, double x, double y)
{
    vec.x += x;
    vec.y += y;
    return vec;
}

t_vec2 vec2_plus_vec2(t_vec2 vec1, t_vec2 vec2)
{
    vec1.x += vec2.x;
    vec1.y += vec2.y;
    return vec1;
}

t_vec2 vec2_sub(t_vec2 vec, double x, double y)
{
    vec.x -= x;
    vec.y -= y;
    return vec;
}

t_vec2 vec2_sub_vec2(t_vec2 vec1, t_vec2 vec2)
{
    vec1.x -= vec2.x;
    vec1.y -= vec2.y;
    return vec1;
}

t_vec2 vec2_multiply(t_vec2 vec, double t)
{
    vec.x *= t;
    vec.y *= t;
    return vec;
}

t_vec2 vec2_multiply_vec2(t_vec2 vec1, t_vec2 vec2)
{
    vec1.x *= vec2.x;
    vec1.y *= vec2.y;
    return vec1;
}

t_vec2 vec2_divide(t_vec2 vec, double t)
{
    vec.x /= t;
    vec.y /= t;
    return vec;
}

double vec2_dot(t_vec2 vec1, t_vec2 vec2)
{
    return (vec1.x * vec2.x + vec1.y * vec2.y);
}

// get unit vector
t_vec2 vec2_normalized(t_vec2 vec)
{
    double len = vec2_length(vec);
    if (len == 0.0)
    {
        printf("vec2_normalized: length is 0, cannot normalize\n");
        exit(1);
    }
    vec.x /= len;
    vec.y /= len;
    return vec;
}