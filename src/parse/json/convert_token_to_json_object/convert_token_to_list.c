/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_token_to_list.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:38:09 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/19 20:28:13 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include <stdlib.h>

static bool	_is_comma_node(t_node *node)
{
	return (*((char *)(node->content)) == ',');
}

static bool	_is_list_start_node(t_node *node)
{
	return (*((char *)(node->content)) == '[');
}

static void	_list_append_value(t_vla *list, t_node *node)
{
	node->type = NODE_VALUE;
	ft_vla_append(list, node);
}

void	convert_token_to_list(t_vla *json_object, size_t base_idx, size_t size)
{
	t_vla	*list;
	t_node	*node;

	list = ft_vla_new();
	while (0 < size)
	{
		node = ft_vla_pop(json_object, base_idx);
		if (node->type != NODE_NO_TYPE)
			ft_vla_append(list, node);
		else if (_is_comma_node(node) || _is_list_start_node(node))
			node_free(node, free);
		else
			_list_append_value(list, node);
		size--;
	}
	node_free(json_object->array[base_idx], free);
	json_object->array[base_idx] = node_new(list, NODE_LIST);
}
