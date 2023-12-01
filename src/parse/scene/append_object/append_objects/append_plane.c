/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:18:23 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/01 17:30:48 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "plane.h"
#include "identifer_and_parameter.h"
#include "define.h"
#include "parse.h"
#include <float.h>

int	append_plane(const t_json_node *node, t_vla *objects)
{
	t_plane	plane;

	if (node->type != NODE_DICT)
		return (ERROR);
	if (query_set_vec3(
			query_create(node, NORMAL, &plane.system.axis_z, true),
			range_create(-1.0, 1.0)) == ERROR
		|| query_set_vec3(
			query_create(node, COORDINATES, &plane.origin, true),
			range_create(-DBL_MAX, DBL_MAX)) == ERROR
		|| try_vec3_unit(&plane.system.axis_z) == ERROR)
		return (ERROR);
	ft_vla_append(objects, plane_object_new(plane.origin, plane.system.axis_z));
	return (SUCCESS);
}
