/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:18:19 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/19 14:24:45 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_node	*node_new(void *content, t_node_type type)
{
	t_node	*node;

	node = (t_node *)ft_xcalloc(1, sizeof(t_node));
	node->content = content;
	node->type = type;
	return (node);
}
