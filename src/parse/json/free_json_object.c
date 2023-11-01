/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_json_object.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 20:03:30 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/28 14:22:30 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include <stddef.h>
#include <stdlib.h>

void	_free_json_object_container(t_vla *json_object)
{
	free(json_object->array);
	free(json_object);
}

void	_recursive_free_json_object(t_json_node *master_node)
{
	t_json_node	*node;
	t_vla		*json_object;

	if (master_node->type == NODE_VALUE)
	{
		free(master_node->value);
		return ;
	}
	json_object = (t_vla *)master_node->value;
	while (0 < json_object->size)
	{
		node = ft_vla_pop(json_object, 0);
		_recursive_free_json_object(node);
		json_node_free(node, NULL);
	}
	_free_json_object_container(json_object);
}

void	free_json_object(t_vla *json_object)
{
	t_json_node	*node;

	node = json_object->array[0];
	_recursive_free_json_object(node);
	json_node_free(node, NULL);
	_free_json_object_container(json_object);
}
