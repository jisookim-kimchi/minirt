#include "struct.h"

t_vec3	vec3(double x, double y, double z);
t_point3	point3(double x, double y, double z);
t_color3	color3(double x, double y, double z);
void	vec_set(t_vec3 *vec3, double x, double y, double z);
void	color_set(t_color3 *color3, double x, double y, double z);
void	point_set(t_point3 *point3, double x, double y, double z);
double	vec3_length_squared(t_vec3 vec);
double      vec3_length(t_vec3 vec);
t_vec3	vec3_add(t_vec3 vec, double x, double y, double z);
t_vec3	vec3_plus_vec3(t_vec3 vec1, t_vec3 vec2);
t_vec3      vec3_sub(t_vec3 vec, double x, double y, double z);
t_vec3      vec3_sub_vec3(t_vec3 vec1, t_vec3 vec2);
t_vec3      vec3_multiply(t_vec3 vec, double t);
t_vec3      vec3_multiply_vec3(t_vec3 vec1, t_vec3 vec2);
t_vec3      vec3_divide(t_vec3 vec, double t);
double	vec3_dot(t_vec3 vec1, t_vec3 vec2);
t_vec3	vec3_cross(t_vec3 vec1, t_vec3 vec2);
t_vec3	vec3_normalized(t_vec3 vec3);