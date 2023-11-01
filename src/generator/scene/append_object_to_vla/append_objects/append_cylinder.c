/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:18:23 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/01 14:39:17 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"
#include "define.h"
#include "fn_type.h"
#include "generator.h"

static void	_append_cylinder_object(t_cylinder cylinder,
								double diameter,
								double hight,
								t_vla *objects)
{
	t_object	*cylinder_object;
	t_cylinder	*new_cylinder;

	new_cylinder = cylinder_new(
			cylinder.center,
			vec3_unit(cylinder.dir),
			diameter / 2,
			hight / 2);
	cylinder_object = object_new(
			new_cylinder,
			cylinder_get_dist,
			cylinder_get_normal,
			cylinder_free);
	ft_vla_append(objects, cylinder_object);
}

int	append_cylinder(const t_json_node *node, t_vla *objects)
{
	t_cylinder			cylinder;
	const t_json_node	*dia_node = select_json_node(node, DIAMETER);
	const t_json_node	*hi_node = select_json_node(node, HEIGHT);
	double				dia;
	double				hi;

	if (list_to_vec3(
			get_list(node, COORDINATES, 3),
			&cylinder.center,
			UNLIMITED,
			UNLIMITED) == ERROR
		|| list_to_vec3(get_list(node, AXIS, 3), &cylinder.dir, -1, 1) == ERROR
		|| json_node_to_double(dia_node, &dia, UNLIMITED, UNLIMITED) == ERROR
		|| json_node_to_double(hi_node, &hi, UNLIMITED, UNLIMITED) == ERROR)
		return (ERROR);
	_append_cylinder_object(cylinder, dia, hi, objects);
	return (SUCCESS);
}
