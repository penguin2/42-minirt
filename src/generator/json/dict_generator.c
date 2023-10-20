/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_generator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:32:46 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/20 21:21:55 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include <stdio.h>

static void	_put_key_and_colon(const char *key, size_t nest_level, int fd)
{
	put_indent_fd(nest_level + 1, fd);
	ft_putstr_fd(key, fd);
	ft_putstr_fd(": ", fd);
}

static t_dict	*_get_dict_from_dict_list(t_node *node)
{
	return ((t_dict *)node->content);
}

void	dict_generator(t_vla *dict_list, int fd, size_t nest_level)
{
	t_dict	*dict;
	t_node	*node;
	size_t	idx;

	ft_putendl_fd("{", fd);
	idx = 0;
	while (idx < dict_list->size)
	{
		dict = _get_dict_from_dict_list(dict_list->array[idx]);
		_put_key_and_colon(dict->key, nest_level, fd);
		node = (t_node *)dict->value;
		if (node->type == NODE_VALUE)
			ft_putstr_fd(node->content, fd);
		else if (node->type == NODE_DICT)
			dict_generator(node->content, fd, (nest_level + 1));
		else if (node->type == NODE_LIST)
			list_generator(node->content, fd, (nest_level + 1));
		if (++idx != dict_list->size)
			ft_putendl_fd(",", fd);
		else
			ft_putendl_fd("", fd);
	}
	put_indent_fd(nest_level, fd);
	ft_putchar_fd('}', fd);
}
