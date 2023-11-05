/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:18:23 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/05 15:13:59 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"
#include "define.h"
#include "generator.h"
#include "utils.h"
#include <float.h>

static void	_append_cylinder_object(t_cylinder cylinder,
								double diameter,
								double hight,
								t_vla *objects)
{
	t_object	*cylinder_object;
	t_cylinder	*new_cylinder;

	new_cylinder = cylinder_new(
			cylinder.center,
			cylinder.dir,
			diameter / 2.0,
			hight / 2.0);
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
	const t_json_node	*diameter_node = select_json_node(node, DIAMETER);
	const t_json_node	*hight_node = select_json_node(node, HEIGHT);
	double				diameter;
	double				hight;

	if (list_to_vec3(get_list(node, COORDINATES, 3),
			&cylinder.center, NO_LIMIT, NO_LIMIT) == ERROR
		|| json_node_to_double(diameter_node, &diameter, EPS, DBL_MAX) == ERROR
		|| json_node_to_double(hight_node, &hight, EPS, DBL_MAX) == ERROR
		|| list_to_vec3(get_list(node, AXIS, 3), &cylinder.dir, -1, 1) == ERROR
		|| try_vec3_unit(&cylinder.dir) == ERROR)
		return (ERROR);
	_append_cylinder_object(cylinder, diameter, hight, objects);
	return (SUCCESS);
}
