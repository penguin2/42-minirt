/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_node_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:18:19 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/27 20:28:50 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_json_node	*json_node_new(char *key, void *value, t_node_type type)
{
	t_json_node	*node;

	node = (t_json_node *)ft_xcalloc(1, sizeof(t_json_node));
	node->key = key;
	node->value = value;
	node->type = type;
	return (node);
}
