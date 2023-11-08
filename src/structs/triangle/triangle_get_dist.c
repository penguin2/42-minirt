/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_get_dist.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:42:38 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/08 18:07:26 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec3.h"
#include "ray.h"
#include "triangle.h"
#include "utils.h"

static bool	_is_outside(const t_triangle *triangle, t_vec3 pos);

bool	triangle_get_dist(const t_object *object, t_ray ray, double *dist)
{
	const t_triangle	*triangle = object->ptr;
	const double		dn = vec3_dot(ray.dir, triangle->normal);
	double				t;

	if (is_zero(dn))
		return (false);
	t = vec3_dot(vec3_sub(triangle->origin, ray.origin), triangle->normal) / dn;
	if (t < 0 || _is_outside(triangle, ray_at(ray, t)))
		return (false);
	*dist = t;
	return (true);
}

static bool	_is_outside(const t_triangle *triangle, t_vec3 pos)
{
	t_vec3	area[2];

	pos = vec3_sub(pos, triangle->origin);
	area[0] = vec3_cross(triangle->edge[0], pos);
	area[1] = vec3_cross(pos, triangle->edge[1]);
	return (vec3_dot(area[0], triangle->normal) < 0
		|| vec3_dot(area[1], triangle->normal) < 0
		|| vec3_len(area[0]) + vec3_len(area[1]) > triangle->area);
}
