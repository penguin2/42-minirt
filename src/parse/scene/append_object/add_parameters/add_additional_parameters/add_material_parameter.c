/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_material_parameter.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:15:06 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/20 21:59:03 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "parse.h"
#include "libcolor.h"
#include "material.h"
#include "object.h"
#include "range.h"
#include <stdbool.h>
#include <float.h>

int	add_material_parameter(const t_json_node *json_node, t_object *object)
{
	t_material	*mat;

	mat = &object->material;
	if (query_set_double(
			query_create(json_node, K_SHININESS, &mat->k_shininess, false),
			range_create(1.0, DBL_MAX)) == ERROR
		|| query_set_double(
			query_create(json_node, K_AMBIENT, &mat->k_ambient, false),
			range_create(0.0, 1.0)) == ERROR
		|| query_set_double(
			query_create(json_node, K_DIFFUSE, &mat->k_diffuse, false),
			range_create(0.0, 1.0)) == ERROR
		|| query_set_double(
			query_create(json_node, K_SPECULAR, &mat->k_specular, false),
			range_create(0.0, 1.0)) == ERROR
		|| query_set_double(
			query_create(json_node, K_REFLECT, &mat->k_reflect, false),
			range_create(0.0, 1.0)) == ERROR
		|| query_set_boolean(query_create(
				json_node, IS_REFLECTIVE, &mat->is_reflective, false)) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
