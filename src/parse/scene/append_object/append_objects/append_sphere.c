/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:18:23 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/20 21:39:21 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sphere.h"
#include "define.h"
#include "parse.h"
#include "utils.h"
#include <float.h>

int	append_sphere(const t_json_node *node, t_vla *objects)
{
	t_sphere			sphere;
	double				diameter;

	if (list_to_vec3(get_list(node, COORDINATES, 3),
			&sphere.center, -DBL_MAX, DBL_MAX) == ERROR
		|| query_set_double(
			query_create(node, DIAMETER, &diameter, true),
			range_create(DBL_MIN, DBL_MAX)) == ERROR)
		return (ERROR);
	ft_vla_append(objects, sphere_object_new(sphere.center, diameter / 2));
	return (SUCCESS);
}
