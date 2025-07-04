
#include <math.h> 
#include <stdio.h>
#include <stdlib.h>

typedef struct s_vec3 t_vec3;
typedef struct s_vec3 t_point3;
typedef struct s_vec3 t_color3;
typedef struct s_ray  t_ray;

typedef struct s_ray
{
	t_point3 orig;
	t_vec3   dir;
} t_ray;

typedef struct s_vec3
{
	double x;
	double y;
	double z;
}	t_vec3;

t_ray		ray(t_point3 orig, t_vec3 dir);
t_point3    ray_at(t_ray *ray, double t);