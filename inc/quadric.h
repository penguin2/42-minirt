/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadric.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 00:17:49 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/30 17:25:33 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUADRIC_H
# define QUADRIC_H

# include "libvec3.h"
# include "object.h"

# define QUADRIC_COEFFICIENT_SIZE 5

typedef enum e_quadric_coefficient
{
	COEFF_A = 0,
	COEFF_B = 1,
	COEFF_C = 2,
	COEFF_D = 3,
	COEFF_E = 4,
}	t_quadric_coefficient;

//   coeff_a(x-center.x)^2
// + coeff_b(y-center.y)^2
// + coeff_c(z-center.z)^2
// + coeff_d(z-center.z)
// = coeff_e
typedef struct s_quadric{
	t_vec3	center;
	double	coeff_array[QUADRIC_COEFFICIENT_SIZE];
}	t_quadric;

t_quadric	*quadric_new(
				t_vec3 center,
				double coeff[QUADRIC_COEFFICIENT_SIZE]);
t_object	*quadric_object_new(
				t_vec3 center,
				double coeff[QUADRIC_COEFFICIENT_SIZE]);
void		quadric_free(void *quadric);
t_color		quadric_get_color(const t_object *object, const t_hit *hit);
bool		quadric_get_dist(const t_object *object, t_ray ray, double *dist);
t_vec3		quadric_get_normal(const t_object *object, t_ray ray, t_vec3 pos);
t_object_id	quadric_get_id(void);

double		quadric_dot(const double coeff_array[QUADRIC_COEFFICIENT_SIZE],
				t_vec3 vec1,
				t_vec3 vec2);

#endif
