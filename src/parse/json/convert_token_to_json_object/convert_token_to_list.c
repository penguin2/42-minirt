/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_token_to_list.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:38:09 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/28 17:26:26 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include <stdlib.h>

static bool	_is_comma_node(t_json_node *node)
{
	return (*((char *)(node->value)) == COMMA);
}

static bool	_is_list_start_node(t_json_node *node)
{
	return (*((char *)(node->value)) == LIST_START);
}

static void	_list_append_value(t_vla *list, t_json_node *node)
{
	node->type = NODE_VALUE;
	ft_vla_append(list, node);
}

/**
* @brief create a list and Replace with a vla of token_node
*        List is a vla of value_node created from VALUE tokens
*
* @param json_object vla of token_node
* @param base_idx Starting index to generate key_vakue_node
* @param size Difference between start index and end index to generate value_node
*/
void	convert_token_to_list(t_vla *json_object, size_t base_idx, size_t size)
{
	t_vla		*list;
	t_json_node	*node;

	list = ft_vla_new();
	while (0 < size)
	{
		node = ft_vla_pop(json_object, base_idx);
		if (node->type != NODE_NO_TYPE)
			ft_vla_append(list, node);
		else if (_is_comma_node(node) || _is_list_start_node(node))
			json_node_free(node, free);
		else
			_list_append_value(list, node);
		size--;
	}
	json_node_free(json_object->array[base_idx], free);
	json_object->array[base_idx] = json_node_new(NULL, list, NODE_LIST);
}
