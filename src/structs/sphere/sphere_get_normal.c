/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_get_normal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:42:58 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/18 15:52:33 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec3.h"
#include "sphere.h"

t_vec3	sphere_get_normal(const t_object *object, t_ray ray, t_vec3 pos)
{
	const t_sphere	*sphere = object->ptr;
	const t_vec3	sphere_to_ray = vec3_sub(ray.origin, sphere->center);

	if (vec3_len(sphere_to_ray) < sphere->radius)
		return (vec3_unit(vec3_sub(sphere->center, pos)));
	return (vec3_unit(vec3_sub(pos, sphere->center)));
}
