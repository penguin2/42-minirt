/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_get_normal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:42:58 by taekklee          #+#    #+#             */
/*   Updated: 2023/12/04 17:48:02 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec3.h"
#include "sphere.h"

t_vec3	sphere_get_normal(
			const t_object *object,
			t_ray ray,
			t_vec3 pos,
			t_vec3 *local_normal)
{
	const t_sphere	*sphere = object->ptr;
	const t_vec3	sphere_to_ray = vec3_sub(ray.origin, sphere->center);
	t_vec3			normal;

	*local_normal = vec3_unit(vec3_sub(pos, sphere->center));
	normal = *local_normal;
	if (object->bump_map != NULL)
		normal = sphere_get_bump_normal(
				object->ptr, object->bump_map, pos, normal);
	if (vec3_len(sphere_to_ray) < sphere->radius)
	{
		*local_normal = vec3_mul(*local_normal, -1.0);
		normal = vec3_mul(normal, -1.0);
	}
	return (normal);
}
