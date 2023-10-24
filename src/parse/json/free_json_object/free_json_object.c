/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_json_object.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:00:04 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/24 17:38:39 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include <stddef.h>
#include <stdlib.h>

void	free_json_object(t_vla *json_object)
{
	t_node	*node;

	node = json_object->array[0];
	if (node->type == NODE_LIST)
		free_list_of_json_object(node->content);
	else if (node->type == NODE_DICT)
		free_dict_of_json_object(node->content);
	node_free(node, NULL);
	free(json_object->array);
	free(json_object);
}
