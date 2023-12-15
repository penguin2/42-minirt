/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_node_to_double.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 20:27:55 by taekklee          #+#    #+#             */
/*   Updated: 2023/12/14 17:52:38 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "message_parse.h"
#include "parse.h"
#include "utils.h"

/**
* @brief Convert a number of string-type to double type
*		 by atof and check if the value is between the upper and lower limits.
*
* @param node Node with the string-type double value expected.
* @param range Valid range of the value to store.
* @param val Pointer to double type to store value.
*
* @return SUCCESS if the conversion of the value
*		  to a double type is successful, otherwise ERROR
*/
int	json_node_to_double(const t_json_node *node, t_range range, double *val)
{
	double	double_val;

	if (node == NULL || node->type != NODE_VALUE)
		return (error_with_message_if(true, INVALID_PARAMETERS));
	if (try_json_node_tof(node, &double_val) == ERROR)
		return (error_with_message_if(true, ATOF_FAILED));
	if (!is_between_min_to_max(double_val, range.start, range.end))
		return (error_with_message_if(true, OUTSIDE_THE_RANGE));
	*val = double_val;
	return (SUCCESS);
}
