/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   query_set_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:10:48 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/21 17:12:07 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "message_parse.h"
#include "parse.h"
#include "utils.h"

static int	_print_and_return_result(bool is_required)
{
	if (is_required)
	{
		print_error(INVALID_COLORS);
		return (ERROR);
	}
	return (SUCCESS);
}

int	query_set_color(t_query query)
{
	const t_json_node	*list_node;
	const t_vla			*list;

	list_node = select_json_node(query.json_node, query.key);
	if (list_node == NULL || list_node->type != NODE_LIST)
		return (_print_and_return_result(query.is_required));
	list = list_node->value;
	if (list->size != 3 || !is_only_value_node(list))
		return (_print_and_return_result(query.is_required));
	return (json_node_to_color(list_node, query.value));
}
