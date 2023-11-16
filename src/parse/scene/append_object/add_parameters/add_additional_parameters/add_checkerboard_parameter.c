/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_checkerboard_parameter.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:15:06 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/17 03:51:13 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "parse.h"
#include "object.h"

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

int	add_checkerboard_parameter(const t_json_node *json_node, t_object *object)
{
	if (_set_boolean(
			json_node, IS_CHECKERBOARD, &object->is_checkerboard) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
