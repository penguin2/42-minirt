/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_open_brackets.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:43:04 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/26 19:34:17 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generator.h"

void	put_open_brackets(t_node *master_node, bool only_val_flag, int fd)
{
	if (master_node->type == NODE_DICT)
		ft_putstr_fd(GENERATOR_DICT_START, fd);
	else if (master_node->type == NODE_LIST)
		ft_putstr_fd(GENERATOR_LIST_START, fd);
	if (((t_vla *)master_node->content)->size != 0 && !only_val_flag)
		ft_putchar_fd('\n', fd);
}
