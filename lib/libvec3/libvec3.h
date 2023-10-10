#ifndef LIBVEC3_H
# define LIBVEC3_H

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

t_vec3	vec3_add(t_vec3 vec1, t_vec3 vec2);
t_vec3	vec3_sub(t_vec3 vec1, t_vec3 vec2);
t_vec3	vec3_dot(t_vec3 vec1, t_vec3 vec2);
t_vec3	vec3_cross(t_vec3 vec1, t_vec3 vec2);
t_vec3	vec3_mul(t_vec3 vec1, double scalar);

t_vec3	vec3_unit(t_vec3 vec);

double	vec3_len(t_vec3 vec);
double	vec3_len_squared(t_vec3 vec);


#endif
