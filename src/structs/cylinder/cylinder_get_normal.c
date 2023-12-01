/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_get_normal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 03:07:49 by taekklee          #+#    #+#             */
/*   Updated: 2023/12/01 17:14:33 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"
#include "libvec3.h"

t_vec3	cylinder_get_normal(const t_object *object, t_ray ray, t_vec3 pos)
{
	const t_cylinder	*cylinder = object->ptr;
	t_vec3				normal;

	normal = vec3_unit(vec3_projected(
				vec3_sub(pos, cylinder->center), cylinder->system.axis_z));
	if (vec3_dot(ray.dir, normal) > 0)
		return (vec3_mul(normal, -1.0));
	return (normal);
}
