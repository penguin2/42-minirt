/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_only_value_node.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:38:14 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/31 19:22:00 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generator.h"

/**
* @brief Determine whether the types of all elements in list are NODE_VALUE
*
* @param list vla of value
*
* @return true if type of all elements of list are NODE_VALUE, otherwise false
*/
bool	is_only_value_node(const t_vla *list)
{
	t_json_node	*node;
	size_t		idx;

	idx = 0;
	while (idx < list->size)
	{
		node = list->array[idx++];
		if (node->type != NODE_VALUE)
			return (false);
	}
	return (true);
}
