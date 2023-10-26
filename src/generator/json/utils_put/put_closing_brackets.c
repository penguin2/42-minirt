/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_closing_brackets.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:44:05 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/26 19:42:01 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generator.h"
#include "libft.h"

void	put_closing_brackets(t_node *master_node,
							size_t nest_level,
							bool only_val_flag,
							int fd)
{
	t_vla	*json_object;

	json_object = master_node->content;
	if (json_object->size != 0)
		put_indent(nest_level, only_val_flag, fd);
	if (master_node->type == NODE_DICT)
		ft_putstr_fd(GENERATOR_DICT_END, fd);
	else if (master_node->type == NODE_LIST)
		ft_putstr_fd(GENERATOR_LIST_END, fd);
	if (nest_level == 0)
		ft_putchar_fd('\n', fd);
}
