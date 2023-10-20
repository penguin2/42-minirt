/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_get_dist.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 02:18:48 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/20 16:00:00 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"
#include "libvec3.h"
#include "utils.h"
#include <math.h>
#include <stdbool.h>

static bool	_get_dist_on_cylinder_plane(
				double roots[NUM_QUADRATIC_EQUATION_ROOTS],
				t_vec3 center_to_ray,
				double radius,
				t_vec3 ray_dir_projected);
static bool	_update_dist_with_validation(
				double *dist,
				double t,
				bool is_valid);
static bool	_is_valid_dist(
				double t,
				double h_offset,
				t_ray ray,
				const t_cylinder *cylinder);

bool	cylinder_get_dist(const t_object *object, t_ray ray, double *dist)
{
	const t_cylinder	*cylinder = object->ptr;
	const double		h_offset = vec3_dot(
			vec3_sub(ray.origin, cylinder->center),
			cylinder->dir);
	const t_vec3		center_adjusted = vec3_add(
			cylinder->center,
			vec3_mul(cylinder->dir, h_offset));
	double				roots[NUM_QUADRATIC_EQUATION_ROOTS];

	if (!_get_dist_on_cylinder_plane(
			roots,
			vec3_sub(ray.origin, center_adjusted),
			cylinder->radius,
			vec3_projected(ray.dir, cylinder->dir)))
		return (false);
	if (_update_dist_with_validation(dist, roots[LOWER_ROOT],
			_is_valid_dist(roots[LOWER_ROOT], h_offset, ray, cylinder))
		|| _update_dist_with_validation(dist, roots[HIGHER_ROOT],
			_is_valid_dist(roots[HIGHER_ROOT], h_offset, ray, cylinder)))
		return (true);
	return (false);
}

static bool	_get_dist_on_cylinder_plane(
				double roots[NUM_QUADRATIC_EQUATION_ROOTS],
				t_vec3 center_to_ray,
				double radius,
				t_vec3 ray_dir_projected)
{
	const double	ray_speed_projected = vec3_len(ray_dir_projected);

	if (is_zero(ray_speed_projected))
		return (false);
	if (!solve_quadratic_equation(
			roots,
			vec3_dot(vec3_unit(ray_dir_projected), center_to_ray),
			vec3_len_squared(center_to_ray) - radius * radius))
		return (false);
	roots[LOWER_ROOT] /= ray_speed_projected;
	roots[HIGHER_ROOT] /= ray_speed_projected;
	return (true);
}

static bool	_update_dist_with_validation(
				double *dist,
				double t,
				bool is_valid)
{
	if (is_valid)
	{
		*dist = t;
		return (true);
	}
	return (false);
}

static bool	_is_valid_dist(
				double t,
				double h_offset,
				t_ray ray,
				const t_cylinder *cylinder)
{
	const double	h_speed = vec3_dot(ray.dir, cylinder->dir);

	return (t > 0 && fabs(h_speed * t + h_offset) < cylinder->half_height);
}
