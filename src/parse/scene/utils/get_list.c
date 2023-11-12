/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 20:57:15 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/10 21:12:19 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include <stddef.h>

/**
* @brief Search for a string matching a key in the dict
*		 that is the value of the node, and return a list
*		 if the list is in accordance with the accept_size.
*
* @param node Node whose value is dict containing the list to be retrieved
* @param key String that is the key to the dict
*			 containing the list you want to retrieve.
* @param accept_size Number of list contents you want to retrieve
*					 if ACCEPT_1_OR_OVER is specified, return the retrieved
*					 list if its size is greater than or equal to 1.
*
* @return if list is found and the list is in accordance with accept_size,
*		  return list.
*		  Otherwise, return NULL.
*/
t_vla	*get_list(const t_json_node *node, const char *key, int accept_size)
{
	const t_json_node	*list_node = select_json_node(node, key);
	t_vla				*list;

	if (list_node == NULL || list_node->type != NODE_LIST)
		return (NULL);
	list = list_node->value;
	if (accept_size == ACCEPT_1_OR_OVER && 0 < list->size)
		return (list);
	else if ((size_t)accept_size == list->size)
		return (list);
	else
		return (NULL);
}
