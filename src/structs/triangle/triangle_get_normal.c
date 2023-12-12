/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_get_normal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:26:32 by taekklee          #+#    #+#             */
/*   Updated: 2023/12/04 17:52:26 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec3.h"
#include "triangle.h"

t_vec3	triangle_get_normal(
			const t_object *object,
			t_ray ray,
			t_vec3 pos,
			t_vec3 *local_normal)
{
	const t_triangle	*triangle = object->ptr;
	t_vec3				normal;

	(void)pos;
	*local_normal = triangle->normal;
	normal = *local_normal;
	if (vec3_dot(ray.dir, normal) > 0)
	{
		*local_normal = vec3_mul(*local_normal, -1.0);
		normal = vec3_mul(normal, -1.0);
	}
	return (normal);
}
