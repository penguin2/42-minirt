/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_texture_map_paramter.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:54:13 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/25 19:42:47 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	add_texture_map_parameter(const t_json_node *json_node, t_object *object)
{
	return (query_set_ppm_reader(
			query_create(
				json_node,
				TEXTURE_MAP,
				&object->texture_map,
				false)));
}
