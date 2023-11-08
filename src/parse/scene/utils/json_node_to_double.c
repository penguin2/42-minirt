/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_node_to_double.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:10:48 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/08 15:47:00 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "parse.h"
#include "message_parse.h"
#include "utils.h"

int	json_node_to_double(const t_json_node *node,
						double *dptr,
						double min,
						double max)
{
	if (node == NULL || node->type != NODE_VALUE)
	{
		print_error(INVALID_PARAMETERS);
		return (ERROR);
	}
	else if (try_json_node_tof(node, dptr) == ERROR)
		return (ERROR);
	else if (is_between_min_to_max(*dptr, min, max))
		return (SUCCESS);
	else
		return (ERROR);
}
