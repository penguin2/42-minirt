/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_generator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:32:46 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/25 15:20:21 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	_put_key_and_colon(const char *key, int fd, size_t nest_level)
{
	put_indent_fd(fd, (nest_level + 1));
	ft_putstr_fd(key, fd);
	ft_putstr_fd(": ", fd);
}

static void	_put_comma_or_new_line(size_t idx, size_t list_of_dict_size, int fd)
{
	if (idx == list_of_dict_size)
		ft_putendl_fd("", fd);
	else
		ft_putendl_fd(",", fd);
}

void	dict_generator(t_vla *list_of_dict, int fd, size_t nest_level)
{
	t_node	*node;
	t_dict	*dict;
	size_t	idx;

	ft_putendl_fd("{", fd);
	idx = 0;
	while (idx < list_of_dict->size)
	{
		dict = list_of_dict->array[idx];
		_put_key_and_colon(dict->key, fd, nest_level);
		node = dict->value;
		if (node->type == NODE_VALUE)
			ft_putstr_fd(node->content, fd);
		else if (node->type == NODE_DICT)
			dict_generator(node->content, fd, (nest_level + 1));
		else if (node->type == NODE_LIST)
			list_generator(node->content, fd, (nest_level + 1));
		idx++;
		_put_comma_or_new_line(idx, list_of_dict->size, fd);
	}
	put_indent_fd(fd, nest_level);
	ft_putchar_fd('}', fd);
}
