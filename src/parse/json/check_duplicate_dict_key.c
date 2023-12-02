/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicate_dict_key.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:54:48 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/02 19:04:21 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include "define.h"
#include <stddef.h>

int	_check_duplicate(t_vla *dict)
{
	size_t		idx;
	char		*prev_key;
	t_json_node	*node;

	prev_key = NULL;
	idx = 0;
	while (idx < dict->size)
	{
		node = (t_json_node *)dict->array[idx++];
		if (is_duplicate(prev_key, node->key))
			return (ERROR);
		prev_key = node->key;
	}
	return (SUCCESS);
}

int	check_duplicate_dict_key(t_json_node *master_node)
{
	t_vla	*vla;
	size_t	idx;

	if (master_node->type == NODE_VALUE)
		return (SUCCESS);
	vla = master_node->value;
	if (master_node->type == NODE_DICT && _check_duplicate(vla) == ERROR)
		return (ERROR);
	idx = 0;
	while (idx < vla->size)
	{
		if (check_duplicate_dict_key(vla->array[idx++]) == ERROR)
			return (ERROR);
	}
	return (SUCCESS);
}
