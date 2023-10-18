/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_get_dist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:22:08 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/18 15:50:44 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec3.h"
#include "sphere.h"
#include <math.h>
#include <stdbool.h>

bool	_get_roots_quadratic_equation(double roots[2], double b, double c);

bool	sphere_get_dist(const t_object *object, t_ray ray, double *dist)
{
	const t_sphere	*sphere = object->ptr;
	const t_vec3	sphere_to_ray = vec3_sub(ray.origin, sphere->center);
	double			roots[2];

	if (!_get_roots_quadratic_equation(
			roots,
			vec3_dot(ray.dir, sphere_to_ray),
			vec3_len_squared(sphere_to_ray) - sphere->radius * sphere->radius)
		|| roots[1] < 0)
		return (false);
	if (roots[0] > 0)
		*dist = roots[0];
	else
		*dist = roots[1];
	return (true);
}

// for the following quadratic equation: ax^2 + 2bx + c = 0, 
// if the roots of the equation exist, it calculates the roots and returns true
// else, it returns false
//
// (when the roots exist, roots[0] < roots[1])
bool	_get_roots_quadratic_equation(double roots[2], double b, double c)
{
	const double	discriminant = b * b - c;
	double			sqrt_d;

	if (discriminant < 0)
		return (false);
	sqrt_d = sqrt(discriminant);
	roots[0] = -b - sqrt_d;
	roots[1] = -b + sqrt_d;
	return (true);
}
