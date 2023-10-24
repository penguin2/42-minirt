/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_dict_of_json_object.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:36:48 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/24 17:37:36 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include <stddef.h>
#include <stdlib.h>

void	free_dict_of_json_object(t_vla *list_of_dict)
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
			free_list_of_json_object(node->content);
			node_free(node, NULL);
		}
		else if (node->type == NODE_DICT)
		{
			free_dict_of_json_object(node->content);
			node_free(node, NULL);
		}
		dict_free(dict, NULL);
	}
	free(list_of_dict->array);
	free(list_of_dict);
}
