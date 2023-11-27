/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_node_to_ppm_reader.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:02:00 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/25 16:11:39 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "message_parse.h"
#include "parse.h"
#include "utils.h"

int	json_node_to_ppm_reader(const t_json_node *node, t_ppm_reader **ptr)
{
	t_ppm_reader	*ppm_reader;

	if (node == NULL || node->type != NODE_VALUE)
		return (error_with_message_if(true, INVALID_FILENAME));
	ppm_reader = ppm_reader_new(node->value);
	if (ppm_reader == NULL)
		return (error_with_message_if(true, INVALID_FILENAME));
	*ptr = ppm_reader;
	return (SUCCESS);
}
