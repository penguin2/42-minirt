/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_generator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:02:02 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/26 19:33:19 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generator.h"
#include "libft.h"
#include "parse.h"
#include <stdbool.h>
#include <stddef.h>

static t_node	*_get_node(void *node, t_node_type type)
{
	if (type == NODE_DICT)
		return (((t_dict *)node)->value);
	else
		return ((t_node *)node);
}

static bool	_is_only_value_node(t_node *master_node)
{
	t_vla	*list;
	t_node	*node;
	size_t	idx;

	if (master_node->type != NODE_LIST)
		return (false);
	list = master_node->content;
	idx = 0;
	while (idx < list->size)
	{
		node = list->array[idx++];
		if (node->type != NODE_VALUE)
			return (false);
	}
	return (true);
}

void	json_generator(t_node *master_node, size_t nest_level, int fd)
{
	size_t	idx;
	t_node	*node;
	t_vla	*json_object;
	bool	only_val_flag;

	only_val_flag = _is_only_value_node(master_node);
	put_open_brackets(master_node, only_val_flag, fd);
	json_object = master_node->content;
	idx = 0;
	while (idx < json_object->size)
	{
		put_indent((nest_level + 1), only_val_flag, fd);
		if (master_node->type == NODE_DICT)
			put_key_and_colon(json_object->array[idx], fd);
		node = _get_node(json_object->array[idx++], master_node->type);
		if (node->type == NODE_VALUE)
			ft_putstr_fd(node->content, fd);
		else
			json_generator(node, (nest_level + 1), fd);
		put_value_separator(idx == json_object->size, only_val_flag, fd);
	}
	put_closing_brackets(master_node, nest_level, only_val_flag, fd);
}
