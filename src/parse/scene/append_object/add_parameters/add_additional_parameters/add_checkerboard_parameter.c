/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_checkerboard_parameter.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:15:06 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/27 18:34:28 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "identifer_and_parameter.h"
#include "define.h"
#include "parse.h"
#include "object.h"

int	add_checkerboard_parameter(const t_json_node *json_node, t_object *object)
{
	return (query_set_boolean(
			query_create(
				json_node,
				IS_CHECKERBOARD,
				&object->is_checkerboard,
				false)));
}
