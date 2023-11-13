/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_light_to_vla.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:50:19 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/13 21:04:04 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "define.h"
#include <stddef.h>

int	append_light_to_vla(const t_json_node *node,
					t_vla *vla,
					const char *identifier,
					int (*append_function)(const t_json_node *, t_vla *))
{
	const t_vla	*list = get_list(node, identifier, ACCEPT_1_OR_OVER);
	t_json_node	*light_node;
	size_t		idx;

	if (list == NULL)
		return (ERROR);
	idx = 0;
	while (idx < list->size)
	{
		light_node = list->array[idx++];
		if (node->type != NODE_DICT
			|| append_function(light_node, vla) == ERROR
			|| add_light_color(light_node, vla->array[vla->size - 1]) == ERROR)
			return (ERROR);
	}
	return (SUCCESS);
}
