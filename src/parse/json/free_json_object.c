/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_json_object.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 20:03:30 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/26 20:39:43 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include <stddef.h>
#include <stdlib.h>

t_node	*_pop_node(t_vla *json_object, t_node_type type)
{
	t_dict	*dict;
	t_node	*node;

	if (type == NODE_DICT)
	{
		dict = (t_dict *)ft_vla_pop(json_object, 0);
		node = dict->value;
		dict_free(dict, NULL);
	}
	else
		node = (t_node *)ft_vla_pop(json_object, 0);
	return (node);
}

void	_recursive_free_json_object(t_node *master_node)
{
	t_node	*node;
	t_vla	*json_object;

	json_object = (t_vla *)master_node->content;
	while (0 < json_object->size)
	{
		node = _pop_node(json_object, master_node->type);
		if (node->type == NODE_VALUE)
			node_free(node, free);
		else
		{
			_recursive_free_json_object(node);
			node_free(node, NULL);
		}
	}
	free(json_object->array);
	free(json_object);
}

void	free_json_object(t_vla *json_object)
{
	t_node	*node;

	node = json_object->array[0];
	_recursive_free_json_object(node);
	node_free(node, NULL);
	free(json_object->array);
	free(json_object);
}
