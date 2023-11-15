/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadric_get_normal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 01:36:40 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/15 18:08:20 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec3.h"
#include "quadric.h"
#include <stdbool.h>

static bool	_is_interior(const t_quadric *quadric, t_vec3 point);

t_vec3	quadric_get_normal(const t_object *object, t_ray ray, t_vec3 pos)
{
	const t_quadric	*quadric = object->ptr;
	t_vec3			normal;

	pos = vec3_sub(pos, quadric->center);
	normal.x = 2 * quadric->coeff_array[COEFF_A] * pos.x;
	normal.y = 2 * quadric->coeff_array[COEFF_B] * pos.y;
	normal.z = 2 * quadric->coeff_array[COEFF_C]
		* pos.z + quadric->coeff_array[COEFF_D];
	normal = vec3_unit(normal);
	if (_is_interior(quadric, ray.origin))
		return (vec3_mul(normal, -1.0));
	return (normal);
}

static bool	_is_interior(const t_quadric *quadric, t_vec3 point)
{
	point = vec3_sub(point, quadric->center);
	return (quadric_dot(quadric->coeff_array, point, point)
		+ quadric->coeff_array[COEFF_D]
		* point.z - quadric->coeff_array[COEFF_E] < 0);
}
