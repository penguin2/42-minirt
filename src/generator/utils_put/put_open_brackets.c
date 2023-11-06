/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_open_brackets.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:43:04 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/27 21:32:11 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generator.h"

void	put_open_brackets(t_json_node *master_node, int fd)
{
	if (master_node->type == NODE_DICT)
		ft_putstr_fd(GENERATOR_DICT_START, fd);
	else if (master_node->type == NODE_LIST)
		ft_putstr_fd(GENERATOR_LIST_START, fd);
	if (((t_vla *)master_node->value)->size != 0)
		ft_putchar_fd('\n', fd);
}
