/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_get_dist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:22:08 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/18 20:51:11 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec3.h"
#include "sphere.h"
#include "utils.h"
#include <math.h>
#include <stdbool.h>

bool	sphere_get_dist(const t_object *object, t_ray ray, double *dist)
{
	const t_sphere	*sphere = object->ptr;
	const t_vec3	sphere_to_ray = vec3_sub(ray.origin, sphere->center);
	double			roots[NUM_QUADRATIC_EQUATION_ROOTS];

	if (!solve_quadratic_equation(
			roots,
			vec3_dot(ray.dir, sphere_to_ray),
			vec3_len_squared(sphere_to_ray) - sphere->radius * sphere->radius)
		|| roots[HIGHER_ROOT] < 0)
		return (false);
	if (roots[LOWER_ROOT] > 0)
		*dist = roots[LOWER_ROOT];
	else
		*dist = roots[HIGHER_ROOT];
	return (true);
}
