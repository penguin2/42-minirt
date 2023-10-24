/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_of_json_object_free.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:35:18 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/24 17:36:15 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include <stdlib.h>

void	free_list_of_json_object(t_vla *list)
{
	t_node	*node;

	while (0 < list->size)
	{
		node = ft_vla_pop(list, 0);
		if (node->type == NODE_VALUE)
			node_free(node, free);
		else if (node->type == NODE_LIST)
		{
			free_list_of_json_object(node->content);
			node_free(node, NULL);
		}
		else if (node->type == NODE_DICT)
		{
			free_dict_of_json_object(node->content);
			node_free(node, NULL);
		}
	}
	free(list->array);
	free(list);
}
