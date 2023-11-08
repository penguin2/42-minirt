/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_get_normal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:26:32 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/08 17:26:58 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec3.h"
#include "triangle.h"

t_vec3	triangle_get_normal(const t_object *object, t_ray ray, t_vec3 pos)
{
	const t_triangle	*triangle = object->ptr;

	(void)pos;
	if (vec3_dot(ray.dir, triangle->normal) > 0)
		return (vec3_mul(triangle->normal, -1.0));
	return (triangle->normal);
}
