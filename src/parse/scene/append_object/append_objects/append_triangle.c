/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_triangle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:18:23 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/15 15:34:24 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "identifer_and_parameter.h"
#include "libvec3.h"
#include "triangle.h"
#include "define.h"
#include "utils.h"
#include "message_parse.h"
#include "parse.h"
#include <math.h>
#include <stdbool.h>
#include <float.h>

int	append_triangle(const t_json_node *node, t_vla *objects)
{
	t_vec3		vertex[3];

	if (query_set_vec3(
			query_create(node, VERTEX1, &vertex[0], true),
			range_create(-DBL_MAX, DBL_MAX)) == ERROR
		|| query_set_vec3(
			query_create(node, VERTEX2, &vertex[1], true),
			range_create(-DBL_MAX, DBL_MAX)) == ERROR
		|| query_set_vec3(
			query_create(node, VERTEX3, &vertex[2], true),
			range_create(-DBL_MAX, DBL_MAX)) == ERROR)
		return (ERROR);
	if (check_triangle_vertex_valid(vertex) == ERROR)
	{
		print_error(VERTEXES_IS_STRAIGHT_LINE);
		return (ERROR);
	}
	ft_vla_append(objects, triangle_object_new(vertex));
	return (SUCCESS);
}
