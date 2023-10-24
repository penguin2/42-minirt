/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_object_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:00:04 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/24 17:01:19 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include <stddef.h>
#include <stdlib.h>

void	node_list_free(t_vla *list);

void	node_dict_free(t_vla *list_of_dict)
{
	t_dict	*dict;
	t_node	*node;

	while (0 < list_of_dict->size)
	{
		dict = ft_vla_pop(list_of_dict, 0);
		node = dict->value;
		if (node->type == NODE_VALUE)
			node_free(node, free);
		else if (node->type == NODE_LIST)
		{
			node_list_free(node->content);
			node_free(node, NULL);
		}
		else if (node->type == NODE_DICT)
		{
			node_dict_free(node->content);
			node_free(node, NULL);
		}
		dict_free(dict, NULL);
	}
	free(list_of_dict->array);
	free(list_of_dict);
}

void	node_list_free(t_vla *list)
{
	t_node	*node;

	while (0 < list->size)
	{
		node = ft_vla_pop(list, 0);
		if (node->type == NODE_VALUE)
			node_free(node, free);
		else if (node->type == NODE_LIST)
		{
			node_list_free(node->content);
			node_free(node, NULL);
		}
		else if (node->type == NODE_DICT)
		{
			node_dict_free(node->content);
			node_free(node, NULL);
		}
	}
	free(list->array);
	free(list);
}

void	json_object_free(t_vla *json_object)
{
	t_node	*node;

	node = json_object->array[0];
	if (node->type == NODE_DICT)
		node_dict_free(node->content);
	else if (node->type == NODE_LIST)
		node_list_free(node->content);
	node_free(node, NULL);
	free(json_object->array);
	free(json_object);
}
