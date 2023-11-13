/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_material_parameter.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:15:06 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/14 16:54:06 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "identifer_and_parameter.h"
#include "parse.h"
#include "libcolor.h"
#include "material.h"
#include "object.h"
#include <stdbool.h>
#include <float.h>

static int	_set_coefficient(const t_json_node *node,
								const char *key,
								double *dptr)
{
	const t_json_node	*coefficient_node = select_json_node(node, key);

	if (coefficient_node == NULL)
		return (SUCCESS);
	else if (json_node_to_double(coefficient_node, dptr, 0.0, 1.0) == ERROR)
		return (ERROR);
	else
		return (SUCCESS);
}

static int	_set_shininess(const t_json_node *node,
							const char *key,
							double *dptr)
{
	const t_json_node	*shininess_node = select_json_node(node, key);

	if (shininess_node == NULL)
		return (SUCCESS);
	else if (json_node_to_double(shininess_node, dptr, 1.0, DBL_MAX) == ERROR)
		return (ERROR);
	else
		return (SUCCESS);
}

static int	_set_boolean(const t_json_node *node, const char *key, bool *ptr)
{
	const t_json_node	*boolean_node = select_json_node(node, key);

	if (boolean_node == NULL)
	{
		*ptr = false;
		return (SUCCESS);
	}
	else if (json_node_to_bool(boolean_node, ptr) == ERROR)
		return (ERROR);
	else
		return (SUCCESS);
}

int	add_material_parameter(const t_json_node *json_node, t_object *object)
{
	t_material	*mat;

	mat = &object->material;
	if (_set_shininess(json_node, K_SHININESS, &mat->k_shininess) == ERROR
		|| _set_coefficient(json_node, K_AMBIENT, &mat->k_ambient) == ERROR
		|| _set_coefficient(json_node, K_DIFFUSE, &mat->k_diffuse) == ERROR
		|| _set_coefficient(json_node, K_SPECULAR, &mat->k_specular) == ERROR
		|| _set_coefficient(json_node, K_REFLECT, &mat->k_reflect) == ERROR
		|| _set_boolean(json_node, IS_REFLECTIVE, &mat->is_reflective) == ERROR)
		return (ERROR);
	else
		return (SUCCESS);
}
