/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libvec3.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:16:26 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/17 18:07:37 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBVEC3_H
# define LIBVEC3_H

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

t_vec3	vec3_create(double x, double y, double z);
t_vec3	vec3_unit_x(void);
t_vec3	vec3_unit_y(void);
t_vec3	vec3_unit_z(void);

t_vec3	vec3_add(t_vec3 vec1, t_vec3 vec2);
t_vec3	vec3_sub(t_vec3 vec1, t_vec3 vec2);
double	vec3_dot(t_vec3 vec1, t_vec3 vec2);
t_vec3	vec3_cross(t_vec3 vec1, t_vec3 vec2);

t_vec3	vec3_mul(t_vec3 vec, double scalar);

t_vec3	vec3_unit(t_vec3 vec);
double	vec3_len(t_vec3 vec);
double	vec3_len_squared(t_vec3 vec);

t_vec3	vec3_projected(t_vec3 vec, t_vec3 normal);
t_vec3	vec3_reflected(t_vec3 vec, t_vec3 normal);
t_vec3	vec3_some_orthogonal(t_vec3 normal);

#endif
