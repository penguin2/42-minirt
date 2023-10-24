/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_generator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:33:23 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/25 15:43:24 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generator.h"

void	list_generator(t_vla *list, int fd, size_t nest_level)
{
	t_node	*node;
	size_t	idx;

	ft_putchar_fd('[', fd);
	idx = 0;
	while (idx < list->size)
	{
		node = list->array[idx];
		if (node->type == NODE_VALUE)
			ft_putstr_fd(node->content, fd);
		else if (node->type == NODE_DICT)
			dict_generator(node->content, fd, (nest_level + 1));
		else if (node->type == NODE_LIST)
			list_generator(node->content, fd, (nest_level + 1));
		idx++;
		if (idx != list->size)
			ft_putstr_fd(", ", fd);
	}
	ft_putchar_fd(']', fd);
}
