/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_node_to_double.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:10:48 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/10 21:10:26 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "parse.h"
#include "message_parse.h"
#include "utils.h"

/**
* @brief Convert a number of string-type to double type
*		 by atof and check if the value is between the upper and lower limits.
*
* @param node Node with string-type numbers as value
* @param dptr Pointer to double type to store value.
* @param min Lower limit of value.
* @param max Upper limit of value.
*
* @return SUCCESS if the conversion of the value
*		  to a double type is successful, otherwise return ERROR
*/
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
