/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_to_json_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:23:20 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/01 19:49:59 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "generator.h"

t_json_node	*vec3_to_json_list(const t_vec3 *vec, const char *key)
{
	t_json_node	*list_node;
	t_vla		*list;

	list_node = json_node_new(ft_strdup(key), ft_vla_new(), NODE_LIST);
	list = list_node->value;
	ft_vla_append(list, double_to_json_list(vec->x, NULL));
	ft_vla_append(list, double_to_json_list(vec->y, NULL));
	ft_vla_append(list, double_to_json_list(vec->z, NULL));
	return (list_node);
}
