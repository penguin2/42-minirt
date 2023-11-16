/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_triangle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:18:23 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/17 02:07:32 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec3.h"
#include "triangle.h"
#include "define.h"
#include "utils.h"
#include "message_parse.h"
#include "parse.h"

static int	_is_vertex_aligned(t_vec3 vertex[3])
{
	double	area;

	area = vec3_len(vec3_cross(
				vec3_sub(vertex[1], vertex[0]),
				vec3_sub(vertex[2], vertex[0])));
	return (is_zero(area));
}

int	append_triangle(const t_json_node *node, t_vla *objects)
{
	t_vec3		vertex[3];

	if (list_to_vec3(get_list(node, VERTEX1, 3),
			&vertex[0], NO_LIMIT, NO_LIMIT) == ERROR
		|| list_to_vec3(get_list(node, VERTEX2, 3),
			&vertex[1], NO_LIMIT, NO_LIMIT) == ERROR
		|| list_to_vec3(get_list(node, VERTEX3, 3),
			&vertex[2], NO_LIMIT, NO_LIMIT) == ERROR
		|| _is_vertex_aligned(vertex))
		return (ERROR);
	ft_vla_append(objects, triangle_object_new(vertex));
	return (SUCCESS);
}
