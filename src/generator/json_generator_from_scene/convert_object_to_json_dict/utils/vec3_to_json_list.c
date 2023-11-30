/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_to_json_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:23:20 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/30 20:01:02 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "parse.h"

static t_json_node	*_new_vec3_node(double val)
{
	return (
		json_node_new(
			NULL,
			ft_ftoa(val, DOUBLE_LIMIT_DIGIT),
			NODE_VALUE)
	);
}

t_json_node	*vec3_to_json_list(const t_vec3 *vec, const char *key)
{
	t_json_node	*list_node;
	t_vla		*list;

	list_node = json_node_new(ft_strdup(key), ft_vla_new(), NODE_LIST);
	list = list_node->value;
	ft_vla_append(list, _new_vec3_node(vec->x));
	ft_vla_append(list, _new_vec3_node(vec->y));
	ft_vla_append(list, _new_vec3_node(vec->z));
	return (list_node);
}
