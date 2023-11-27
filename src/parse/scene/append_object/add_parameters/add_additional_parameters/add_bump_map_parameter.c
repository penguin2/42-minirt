/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_bump_map_parameter.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:15:06 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/25 15:55:09 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
