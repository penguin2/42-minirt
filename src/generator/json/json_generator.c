/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_generator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:55:02 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/20 15:33:46 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include <stddef.h>

void	json_generator(t_vla *json_object, int fd)
{
	const t_node	*node = (t_node *)json_object->array[0];

	if (node->type == NODE_DICT)
		dict_generator(node->content, fd, 0);
	else if (node->type == NODE_LIST)
		list_generator(node->content, fd, 0);
}
