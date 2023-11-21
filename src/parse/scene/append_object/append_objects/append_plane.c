/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:18:23 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/21 16:07:50 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "plane.h"
#include "define.h"
#include "parse.h"
#include <float.h>

int	append_plane(const t_json_node *node, t_vla *objects)
{
	t_plane	plane;

	if (node->type != NODE_DICT)
		return (ERROR);
	if (query_set_vec3(
			query_create(node, NORMAL, &plane.normal, true),
			range_create(-1.0, 1.0)) == ERROR
		|| query_set_vec3(
			query_create(node, COORDINATES, &plane.origin, true),
			range_create(-DBL_MAX, DBL_MAX)) == ERROR
		|| try_vec3_unit(&plane.normal) == ERROR)
		return (ERROR);
	ft_vla_append(objects, plane_object_new(plane.origin, plane.normal));
	return (SUCCESS);
}
