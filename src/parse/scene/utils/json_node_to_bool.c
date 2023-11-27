/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_node_to_bool.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:10:48 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/24 00:15:03 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "message_parse.h"
#include "parse.h"
#include "utils.h"

int	json_node_to_bool(const t_json_node *node, bool *val)
{
	const char	*boolean_str;
	bool		boolean_val;

	if (node == NULL || node->type != NODE_VALUE)
		return (error_with_message_if(true, INVALID_BOOLEAN));
	boolean_str = node->value;
	if (ft_is_equal_str(boolean_str, TRUE_STRING)
		|| ft_is_equal_str(boolean_str, TRUE_NUMBER))
		boolean_val = true;
	else if (ft_is_equal_str(boolean_str, FALSE_STRING)
		|| ft_is_equal_str(boolean_str, FALSE_NUMBER))
		boolean_val = false;
	else
		return (error_with_message_if(true, INVALID_BOOLEAN));
	*val = boolean_val;
	return (SUCCESS);
}
