/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_triangle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:18:23 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/14 14:32:25 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec3.h"
#include "triangle.h"
#include "define.h"
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

int	append_triangle(const t_json_node *node, t_vla *objects)
{
	t_vec3				vertex[3];

	if (list_to_vec3(get_list(node, VERTEX1, 3),
			&vertex[0], NO_LIMIT, NO_LIMIT) == ERROR
		|| list_to_vec3(get_list(node, VERTEX2, 3),
			&vertex[1], NO_LIMIT, NO_LIMIT) == ERROR
		|| list_to_vec3(get_list(node, VERTEX3, 3),
			&vertex[2], NO_LIMIT, NO_LIMIT) == ERROR)
		return (ERROR);
	_append_triangle_object(vertex, objects);
	return (SUCCESS);
}
