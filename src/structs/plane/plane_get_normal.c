/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_get_normal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 23:14:00 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/19 23:27:42 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec3.h"
#include "plane.h"

t_vec3	plane_get_normal(const t_object *object, t_ray ray, t_vec3 pos)
{
	const t_plane	*plane = object->ptr;

	(void)pos;
	if (vec3_dot(ray.dir, plane->normal) > 0)
		return (vec3_mul(plane->normal, -1.0));
	return (plane->normal);
}
