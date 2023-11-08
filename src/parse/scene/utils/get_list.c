/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 20:57:15 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/08 15:48:14 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include <stddef.h>

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
