/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_to_json_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:23:20 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/02 14:24:47 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generator.h"

t_json_node	*vec3_to_json_list_node(const t_vec3 *vec, const char *key)
{
	t_json_node	*json_list_node;
	t_vla		*list;

	json_list_node = json_node_new(ft_strdup(key), ft_vla_new(), NODE_LIST);
	list = json_list_node->value;
	ft_vla_append(list, double_to_json_value_node(vec->x, NULL));
	ft_vla_append(list, double_to_json_value_node(vec->y, NULL));
	ft_vla_append(list, double_to_json_value_node(vec->z, NULL));
	return (json_list_node);
}
