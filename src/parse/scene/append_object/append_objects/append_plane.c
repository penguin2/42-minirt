/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:18:23 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/20 21:45:07 by taekklee         ###   ########.fr       */
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
	if (list_to_vec3(get_list(node, NORMAL, 3), &plane.normal, -1, 1) == ERROR
		|| list_to_vec3(get_list(node, COORDINATES, 3),
			&plane.origin, -DBL_MAX, DBL_MAX) == ERROR
		|| try_vec3_unit(&plane.normal) == ERROR)
		return (ERROR);
	ft_vla_append(objects, plane_object_new(plane.origin, plane.normal));
	return (SUCCESS);
}
