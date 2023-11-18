/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_triangle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:18:23 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/18 23:49:55 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec3.h"
#include "triangle.h"
#include "define.h"
#include "utils.h"
#include "message_parse.h"
#include "parse.h"
#include <math.h>
#include <stdbool.h>

static bool	_is_two_vecs_aligned(t_vec3 vec1, t_vec3 vec2)
{
	const double	dot = vec3_dot(vec3_unit(vec1), vec3_unit(vec2));

	return (is_zero(fabs(dot) - 1));
}

static int	_check_triangle_vertex_valid(t_vec3 vertex[3])
{
	t_vec3	edge[2];

	edge[0] = vec3_sub(vertex[1], vertex[0]);
	edge[1] = vec3_sub(vertex[2], vertex[0]);
	if (is_zero(vec3_len(edge[0])) || is_zero(vec3_len(edge[1]))
		|| _is_two_vecs_aligned(edge[0], edge[1]))
	{
		print_error(VERTEXES_IS_STRAIGHT_LINE);
		return (ERROR);
	}
	return (SUCCESS);
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
		|| _check_triangle_vertex_valid(vertex) == ERROR)
		return (ERROR);
	ft_vla_append(objects, triangle_object_new(vertex));
	return (SUCCESS);
}
