/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_triangle_vertex_valid.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:46:39 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/13 14:47:30 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "utils.h"
#include "message_parse.h"
#include <math.h>

static bool	_is_two_vecs_aligned(t_vec3 vec1, t_vec3 vec2)
{
	const double	dot = vec3_dot(vec3_unit(vec1), vec3_unit(vec2));

	return (is_zero(fabs(dot) - 1));
}

int	check_triangle_vertex_valid(t_vec3 vertex[3])
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
