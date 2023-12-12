/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_get_normal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 03:07:49 by taekklee          #+#    #+#             */
/*   Updated: 2023/12/04 17:47:35 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"
#include "libvec3.h"

t_vec3	cylinder_get_normal(
			const t_object *object,
			t_ray ray,
			t_vec3 pos,
			t_vec3 *local_normal)
{
	const t_cylinder	*cylinder = object->ptr;
	t_vec3				normal;

	*local_normal = vec3_unit(vec3_projected(
				vec3_sub(pos, cylinder->center), cylinder->system.axis_z));
	normal = *local_normal;
	if (object->bump_map != NULL)
		normal = cylinder_get_bump_normal(
				object->ptr, object->bump_map, pos, normal);
	if (vec3_dot(ray.dir, *local_normal) > 0)
	{
		*local_normal = vec3_mul(*local_normal, -1.0);
		normal = vec3_mul(normal, -1.0);
	}
	return (normal);
}
