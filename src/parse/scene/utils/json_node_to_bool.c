/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_node_to_bool.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:10:48 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/20 22:51:11 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "parse.h"
#include "message_parse.h"
#include "utils.h"
#include "libft.h"
#include <stdbool.h>

static int	_print_and_return_error(void)
{
	print_error(INVALID_BOOLEAN);
	return (ERROR);
}

int	json_node_to_bool(const t_json_node *node, bool *val)
{
	const char	*boolean_str;
	bool		boolean_val;

	if (node == NULL || node->type != NODE_VALUE)
		return (_print_and_return_error());
	boolean_str = node->value;
	if (ft_is_equal_str(boolean_str, TRUE_STRING)
		|| ft_is_equal_str(boolean_str, TRUE_NUMBER))
		boolean_val = true;
	else if (ft_is_equal_str(boolean_str, FALSE_STRING)
		|| ft_is_equal_str(boolean_str, FALSE_NUMBER))
		boolean_val = false;
	else
		return (_print_and_return_error());
	*val = boolean_val;
	return (SUCCESS);
}
