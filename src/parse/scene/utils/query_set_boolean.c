/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   query_set_boolean.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:47:40 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/23 18:43:21 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "message_parse.h"
#include "parse.h"
#include "utils.h"

int	query_set_boolean(t_query query)
{
	const t_json_node	*value_node;

	value_node = select_json_node(query.json_node, query.key);
	if (value_node == NULL)
		return (error_with_message_if(query.is_required, INVALID_PARAMETERS));
	return (json_node_to_bool(value_node, query.value));
}
