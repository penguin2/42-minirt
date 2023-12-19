/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadric_get_dist.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 01:09:50 by taekklee          #+#    #+#             */
/*   Updated: 2023/12/19 18:20:00 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quadric.h"
#include "utils.h"
#include <float.h>

static bool	_solve_quadric_ray_equation(
				const t_quadric *quadric,
				t_ray ray,
				double roots[NUM_QUADRATIC_EQUATION_ROOTS]);

bool	quadric_get_dist(const t_object *object, t_ray ray, double *dist)
{
	const t_quadric	*quadric = object->ptr;
	double			roots[NUM_QUADRATIC_EQUATION_ROOTS];

	if (!_solve_quadric_ray_equation(quadric, ray, roots)
		|| !is_higher(roots[HIGHER_ROOT], SQRT_EPS))
		return (false);
	if (is_higher(roots[LOWER_ROOT], SQRT_EPS))
		*dist = roots[LOWER_ROOT];
	else
		*dist = roots[HIGHER_ROOT];
	return (true);
}

static bool	_solve_quadric_ray_equation(
				const t_quadric *quadric,
				t_ray ray,
				double roots[NUM_QUADRATIC_EQUATION_ROOTS])
{
	const t_vec3	quadric_to_ray = vec3_sub(ray.origin, quadric->center);
	const double	a
		= quadric_dot(quadric->coeff_array, ray.dir, ray.dir);
	const double	b
		= 2 * quadric_dot(quadric->coeff_array, ray.dir, quadric_to_ray)
		+ quadric->coeff_array[COEFF_D] * ray.dir.z;
	const double	c
		= quadric_dot(quadric->coeff_array, quadric_to_ray, quadric_to_ray)
		+ quadric->coeff_array[COEFF_D]
		* quadric_to_ray.z - quadric->coeff_array[COEFF_E];

	if (is_zero(a))
	{
		if (is_zero(b))
			return (false);
		roots[LOWER_ROOT] = -c / b;
		roots[HIGHER_ROOT] = roots[LOWER_ROOT];
		return (true);
	}
	return (solve_quadratic_equation(roots, b / 2 / a, c / a));
}
