/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_node_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:21:00 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/27 20:29:57 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include <stdlib.h>

void	json_node_free(t_json_node *node, void (free_value)(void *))
{
	if (node->key != NULL)
		free(node->key);
	if (free_value != NULL && node->value != NULL)
		free_value(node->value);
	free(node);
}
