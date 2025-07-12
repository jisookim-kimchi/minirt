// change to .h file 

typedef struct s_camera t_camera;
typedef struct s_canvas t_canvas;
typedef struct s_vec3 t_vec3;
typedef struct s_vec3 t_point3;
typedef struct s_vec3 t_color3;
typedef struct s_ray  t_ray;

typedef struct s_vec4
{
	float x;
	float y;
	float z;
	float w;
}	t_vec4;

typedef struct s_vec2
{
	float x;
	float y;
}	t_vec2;

typedef struct s_canvas
{
	int	width;
	int	height;
} t_canvas;

typedef struct s_ray
{
	t_point3 orig;
	t_vec3   dir;
} t_ray;

// change it later double to float
typedef struct s_vec3
{
	double x;
	double y;
	double z;
}	t_vec3;

t_ray		ray(t_point3 orig, t_vec3 dir);
t_point3    ray_at(t_ray *ray, double t);

t_vec3		vec3(double x, double y, double z);
t_vec3		vec3_one();
t_point3	point3(double x, double y, double z);
t_color3	color3(double x, double y, double z);
void		vec3_set(t_vec3 *vec3, double x, double y, double z);
void		color_set(t_color3 *color3, double x, double y, double z);
void		point_set(t_point3 *point3, double x, double y, double z);
double		vec3_length_squared(t_vec3 vec);
double      vec3_length(t_vec3 vec);
t_vec3		vec3_add(t_vec3 vec, double x, double y, double z);
t_vec3		vec3_plus_vec3(t_vec3 vec1, t_vec3 vec2);
t_vec3      vec3_sub(t_vec3 vec, double x, double y, double z);
t_vec3      vec3_sub_vec3(t_vec3 vec1, t_vec3 vec2);
t_vec3      vec3_multiply(t_vec3 vec, double t);
t_vec3      vec3_multiply_vec3(t_vec3 vec1, t_vec3 vec2);
t_vec3      vec3_divide(t_vec3 vec, double t);
double		vec3_dot(t_vec3 vec1, t_vec3 vec2);
t_vec3		vec3_cross(t_vec3 vec1, t_vec3 vec2);
t_vec3		vec3_normalized(t_vec3 vec3);


//vector4.c

t_vec4 vec4(float x, float y, float z, float w);
t_vec4 vec4_from_vec3(t_vec3 v3, int is_point);
t_vec4 vec4_from_vec2(t_vec2 v2, int is_point);

t_vec2 vec4_to_vec2(t_vec4 v4);
t_vec3 vec4_to_vec3(t_vec4 v4);

t_vec4	vec4_add(t_vec4 a, t_vec4 b);
t_vec4	vec4_sub(t_vec4 a, t_vec4 b);
t_vec4	vec4_mul(t_vec4 a, float scale);
t_vec4	vec4_div(t_vec4 a, float scale);
float	vec4_dot(t_vec4 a, t_vec4 b);
float	vec4_size(t_vec4 v);
float	vec4_size_squared(t_vec4 v);
t_vec4	vec4_negate(t_vec4 v);
t_vec4	vec4_normalize(t_vec4 v);
int		vec4_equals_tol(t_vec4 a, t_vec4 b, float tolerance);
float	vec4_max_component(t_vec4 v);

extern const t_vec4 VEC4_ZERO;
extern const t_vec4 VEC4_ONE;
extern const t_vec4 VEC4_UNIT_X;
extern const t_vec4 VEC4_UNIT_Y;
extern const t_vec4 VEC4_UNIT_Z;
extern const t_vec4 VEC4_UNIT_W;