/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_token_to_dict.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:38:59 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/24 17:00:36 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include <stdlib.h>

static t_dict	*_new_dict_node(t_vla *json_object, size_t base_idx)
{
	t_node	*key_node;
	t_node	*value_node;
	t_dict	*dict;

	node_free(ft_vla_pop(json_object, base_idx), free);
	key_node = ft_vla_pop(json_object, base_idx);
	node_free(ft_vla_pop(json_object, base_idx), free);
	value_node = ft_vla_pop(json_object, base_idx);
	if (value_node->type == NODE_NO_TYPE)
		value_node->type = NODE_VALUE;
	dict = dict_new(key_node->content, value_node);
	node_free(key_node, free);
	return (dict);
}

void	convert_token_to_dict(t_vla *json_object, size_t base_idx, size_t size)
{
	t_vla	*list_of_dict;
	t_dict	*dict;

	list_of_dict = ft_vla_new();
	if (size == PATTERN_NO_CONTENT_IN_DICT)
		node_free(ft_vla_pop(json_object, base_idx), free);
	while (1 < size)
	{
		dict = _new_dict_node(json_object, base_idx);
		ft_vla_append(list_of_dict, dict);
		size -= SIZE_OF_DICT_TOKEN;
	}
	node_free(json_object->array[base_idx], free);
	json_object->array[base_idx] = node_new(list_of_dict, NODE_DICT);
}
