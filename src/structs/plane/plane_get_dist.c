/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_get_dist.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 22:46:36 by taekklee          #+#    #+#             */
/*   Updated: 2023/12/01 17:28:55 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec3.h"
#include "plane.h"
#include "utils.h"

bool	plane_get_dist(const t_object *object, t_ray ray, double *dist)
{
	const t_plane	*plane = object->ptr;
	const double	dn = vec3_dot(ray.dir, plane->system.axis_z);
	double			t;

	if (is_zero(dn))
		return (false);
	t = vec3_dot(vec3_sub(plane->origin, ray.origin), plane->system.axis_z)
		/ dn;
	if (t < 0)
		return (false);
	*dist = t;
	return (true);
}
