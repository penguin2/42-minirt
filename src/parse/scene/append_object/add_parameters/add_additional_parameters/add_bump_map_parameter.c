/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_bump_map_parameter.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:15:06 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/28 23:07:00 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "identifer_and_parameter.h"
#include "parse.h"

int	add_bump_map_parameter(const t_json_node *json_node, t_object *object)
{
	return (query_set_ppm_reader(
			query_create(
				json_node,
				BUMP_MAP,
				&object->bump_map,
				false)));
}
