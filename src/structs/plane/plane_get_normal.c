/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_get_normal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 23:14:00 by taekklee          #+#    #+#             */
/*   Updated: 2023/12/04 17:47:56 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec3.h"
#include "plane.h"

t_vec3	plane_get_normal(
			const t_object *object,
			t_ray ray,
			t_vec3 pos,
			t_vec3 *local_normal)
{
	const t_plane	*plane = object->ptr;
	t_vec3			normal;

	*local_normal = plane->system.axis_z;
	normal = *local_normal;
	if (object->bump_map != NULL)
		normal = plane_get_bump_normal(
				object->ptr, object->bump_map, pos, normal);
	if (vec3_dot(ray.dir, plane->system.axis_z) > 0)
	{
		*local_normal = vec3_mul(*local_normal, -1.0);
		normal = vec3_mul(normal, -1.0);
	}
	return (normal);
}
