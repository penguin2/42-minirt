/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_object_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:17:49 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/21 16:05:36 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "identifer_and_parameter.h"
#include "define.h"

int	add_object_color(const t_json_node *json_node, t_object *object)
{
	return (
		query_set_color(
			query_create(json_node, COLORS, &object->color, true)
		)
	);
}
