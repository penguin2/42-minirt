/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_node_to_bool.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:10:48 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/14 17:08:21 by rikeda           ###   ########.fr       */
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

int	json_node_to_bool(const t_json_node *node, bool *ptr)
{
	const char	*boolean;

	if (node == NULL || node->type != NODE_VALUE)
		return (_print_and_return_error());
	boolean = node->value;
	if (ft_is_equal_str(boolean, TRUE_STRING)
		|| ft_is_equal_str(boolean, TRUE_NUMBER))
	{
		*ptr = true;
		return (SUCCESS);
	}
	else if (ft_is_equal_str(boolean, FALSE_STRING)
		|| ft_is_equal_str(boolean, FALSE_NUMBER))
	{
		*ptr = false;
		return (SUCCESS);
	}
	else
		return (_print_and_return_error());
}
