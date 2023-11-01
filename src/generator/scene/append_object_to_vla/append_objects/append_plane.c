/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:18:23 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/01 19:40:43 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fn_type.h"
#include "plane.h"
#include "define.h"
#include "generator.h"

static void	_append_plane_object(t_plane plane, t_vla *objects)
{
	t_plane		*new_plane;
	t_object	*plane_object;

	new_plane = plane_new(plane.origin, vec3_unit(plane.normal));
	plane_object = object_new(
			new_plane,
			plane_get_dist,
			plane_get_normal,
			plane_free);
	ft_vla_append(objects, plane_object);
}

int	append_plane(const t_json_node *node, t_vla *objects)
{
	t_plane	plane;

	if (node->type != NODE_DICT)
		return (ERROR);
	if (list_to_vec3(get_list(node, NORMAL, 3), &plane.normal, -1, 1) == ERROR
		|| list_to_vec3(
			get_list(node, COORDINATES, 3),
			&plane.origin,
			UNLIMITED,
			UNLIMITED) == ERROR)
		return (ERROR);
	_append_plane_object(plane, objects);
	return (SUCCESS);
}
