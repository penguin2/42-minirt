/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   query_set_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:10:48 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/24 12:47:56 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "message_parse.h"
#include "parse.h"
#include "utils.h"

int	query_set_color(t_query query)
{
	const t_json_node	*list_node;

	list_node = select_json_node(query.json_node, query.key);
	if (list_node == NULL)
		return (error_with_message_if(query.is_required, INVALID_COLORS));
	if (!is_list_with_value_nodes(list_node, 3))
		return (error_with_message_if(true, INVALID_COLORS));
	return (json_node_to_color(list_node, query.value));
}
