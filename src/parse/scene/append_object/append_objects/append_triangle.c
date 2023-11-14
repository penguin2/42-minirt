/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_triangle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:18:23 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/14 21:45:36 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec3.h"
#include "triangle.h"
#include "define.h"
#include "utils.h"
#include "message_parse.h"
#include "parse.h"

static void	_append_triangle_object(t_vec3 vertex[3], t_vla *objects)
{
	t_triangle	*new_triangle;
	t_object	*triangle_object;

	new_triangle = triangle_new(vertex);
	triangle_object = object_new(
			new_triangle,
			triangle_get_dist,
			triangle_get_normal,
			triangle_free);
	ft_vla_append(objects, triangle_object);
}

static int	_check_vertexes_are_in_straight_line(t_vec3 vertex[3])
{
	const t_vec3	ab = vec3_sub(vertex[1], vertex[0]);
	const t_vec3	bc = vec3_sub(vertex[2], vertex[1]);
	const double	len_ab = vec3_len(ab);
	const double	len_bc = vec3_len(bc);
	t_vec3			sub_bc_from_ab;

	if (is_zero(len_ab) || is_zero(len_bc))
	{
		print_error(VERTEXES_IS_STRAIGHT_LINE);
		return (ERROR);
	}
	sub_bc_from_ab = vec3_sub(
			vec3_mul(ab, 1 / len_ab),
			vec3_mul(bc, 1 / len_bc)
			);
	if (is_zero(vec3_len(sub_bc_from_ab)))
	{
		print_error(VERTEXES_IS_STRAIGHT_LINE);
		return (ERROR);
	}
	else
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
		|| _check_vertexes_are_in_straight_line(vertex) == ERROR)
		return (ERROR);
	_append_triangle_object(vertex, objects);
	return (SUCCESS);
}
