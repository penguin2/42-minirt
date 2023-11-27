/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_list_with_value_nodes.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:56:22 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/24 00:00:37 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

/**
* @brief check whether the given node is list node with desired size
*
* @param node  given node to check its validation
* @param size  desired size of the list node

* @return true if
* 		1. the type of the given node is NODE_LIST
* 	and 2. the size of the list is exactly the given size
* 	and 3. all the components of the list are value type nodes,
* 		otherwise false
*
* all elements of list are NODE_VALUE, otherwise false
*/
bool	is_list_with_value_nodes(const t_json_node *node, size_t size)
{
	const t_vla	*list;

	if (node->type != NODE_LIST)
		return (false);
	list = node->value;
	return (list->size == size && is_only_value_node(list));
}
