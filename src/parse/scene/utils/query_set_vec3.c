/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   query_set_vec3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:10:48 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/24 12:48:15 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "message_parse.h"
#include "parse.h"
#include "utils.h"

int	query_set_vec3(t_query query, t_range range)
{
	const t_json_node	*list_node;

	list_node = select_json_node(query.json_node, query.key);
	if (list_node == NULL)
		return (error_with_message_if(query.is_required, INVALID_VECTOR));
	if (!is_list_with_value_nodes(list_node, 3))
		return (error_with_message_if(true, INVALID_VECTOR));
	return (json_node_to_vec3(list_node, range, query.value));
}
