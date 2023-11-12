/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_json_object.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 18:51:50 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/10 21:29:15 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "libft.h"
#include <stddef.h>

/**
* @brief Find node in dict that have the same string as the key
*
* @param master_node Node with dict as value with the node
*					 to be retrieved as value.
* @param key String that is the key to the dict
*			 containing the list you want to retrieve.
*
* @return return the node to be retrieved if found, otherwise return NULL.
*/
t_json_node	*select_json_node(const t_json_node *master_node, const char *key)
{
	size_t		idx;
	t_vla		*dict;
	t_json_node	*node;

	if (master_node->type != NODE_DICT)
		return (NULL);
	dict = master_node->value;
	idx = 0;
	while (idx < dict->size)
	{
		node = dict->array[idx++];
		if (ft_is_equal_str(node->key, key))
			return (node);
	}
	return (NULL);
}
