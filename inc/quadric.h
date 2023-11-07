/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadric.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 00:17:49 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/08 02:01:07 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUADRIC_H
# define QUADRIC_H

# include "libvec3.h"
# include "object.h"

//   (coeff_quadratic.x)x^2
// + (coeff_quadratic.y)y^2
// + (coeff_quadratic.z)z^2
// + (coeff_z)z
// = coeff_c
typedef struct s_quadric{
	t_vec3	center;
	t_vec3	coeff_quadratic;
	double	coeff_z;
	double	coeff_c;
}	t_quadric;

t_quadric	*quadric_new(
				t_vec3 center,
				t_vec3 coeff_quadratic,
				double coeff_z,
				double constant);
void		quadric_free(void *quadric);
bool		quadric_get_dist(const t_object *object, t_ray ray, double *dist);
t_vec3		quadric_get_normal(const t_object *object, t_ray ray, t_vec3 pos);
double		quadric_dot(t_vec3 coeff, t_vec3 vec1, t_vec3 vec2);

#endif
