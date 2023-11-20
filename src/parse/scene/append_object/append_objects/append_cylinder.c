/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:18:23 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/20 21:46:24 by taekklee         ###   ########.fr       */
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
	double				diameter;
	double				height;

	if (list_to_vec3(get_list(node, COORDINATES, 3),
			&cylinder.center, -DBL_MAX, DBL_MAX) == ERROR
		|| list_to_vec3(get_list(node, AXIS, 3),
			&cylinder.dir, -1, 1) == ERROR
		|| try_vec3_unit(&cylinder.dir) == ERROR
		|| query_set_double(
			query_create(node, DIAMETER, &diameter, true),
			range_create(DBL_MIN, DBL_MAX)) == ERROR
		|| query_set_double(
			query_create(node, HEIGHT, &height, true),
			range_create(DBL_MIN, DBL_MAX)) == ERROR)
		return (ERROR);
	ft_vla_append(objects, cylinder_object_new(
			cylinder.center,
			cylinder.dir,
			diameter / 2.0,
			height / 2.0));
	return (SUCCESS);
}
