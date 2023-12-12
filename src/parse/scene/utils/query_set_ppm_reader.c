/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   query_set_ppm_reader.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:57:19 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/25 16:00:57 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "message_parse.h"
#include "parse.h"
#include "utils.h"

int	query_set_ppm_reader(t_query query)
{
	const t_json_node	*filename_node;

	filename_node = select_json_node(query.json_node, query.key);
	if (filename_node == NULL)
		return (error_with_message_if(query.is_required, INVALID_PARAMETERS));
	return (json_node_to_ppm_reader(filename_node, query.value));
}
