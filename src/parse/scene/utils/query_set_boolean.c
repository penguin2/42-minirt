/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   query_set_boolean.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:47:40 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/20 22:31:36 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "message_parse.h"
#include "parse.h"
#include "utils.h"

int	query_set_boolean(t_query query)
{
	const t_json_node	*value_node;

	value_node = select_json_node(query.json_node, query.key);
	if (value_node == NULL)
	{
		if (query.is_required)
		{
			print_error(INVALID_PARAMETERS);
			return (ERROR);
		}
		return (SUCCESS);
	}
	return (json_node_to_bool(value_node, query.value));
}
