/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:21:00 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/19 16:23:46 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include <stdlib.h>

void	node_free(t_node *node, void (free_content)(void *))
{
	if (free_content != NULL && node->content != NULL)
		free_content(node->content);
	free(node);
}
