/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:18:23 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/17 01:56:18 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"
#include "define.h"
#include "parse.h"
#include "utils.h"
#include <float.h>

int	append_cylinder(const t_json_node *node, t_vla *objects)
{
	t_cylinder			cylinder;
	const t_json_node	*diameter_node = select_json_node(node, DIAMETER);
	const t_json_node	*height_node = select_json_node(node, HEIGHT);
	double				diameter;
	double				height;

	if (json_node_to_double(diameter_node, &diameter, DBL_MIN, DBL_MAX) == ERROR
		|| json_node_to_double(height_node, &height, DBL_MIN, DBL_MAX) == ERROR
		|| list_to_vec3(get_list(node, COORDINATES, 3),
			&cylinder.center, NO_LIMIT, NO_LIMIT) == ERROR
		|| list_to_vec3(get_list(node, AXIS, 3), &cylinder.dir, -1, 1) == ERROR
		|| try_vec3_unit(&cylinder.dir) == ERROR)
		return (ERROR);
	ft_vla_append(objects, cylinder_object_new(
			cylinder.center,
			cylinder.dir,
			diameter / 2.0,
			height / 2.0));
	return (SUCCESS);
}
