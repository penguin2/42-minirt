/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   query_set_double.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:10:48 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/20 23:09:46 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "message_parse.h"
#include "parse.h"
#include "utils.h"
#include <stdio.h>

int	query_set_double(t_query query, t_range range)
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
	return (json_node_to_double(value_node, range, query.value));
}
