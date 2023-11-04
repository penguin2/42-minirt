/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_object_to_vla.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:50:19 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/04 15:40:44 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include "generator.h"
#include "define.h"
#include <stddef.h>

int	append_object_to_vla(const t_json_node *node,
					t_vla *vla,
					const char *identifier,
					int (*append_function)(const t_json_node *, t_vla *))
{
	const t_vla	*list = get_list(node, identifier, ACCEPT_1_OR_OVER);
	t_json_node	*object_node;
	size_t		idx;

	if (list == NULL)
		return (SUCCESS);
	idx = 0;
	while (idx < list->size)
	{
		object_node = list->array[idx++];
		if (node->type != NODE_DICT
			|| append_function(object_node, vla) == ERROR
			|| add_color_parameter(object_node,
				vla->array[vla->size - 1]) == ERROR
			|| add_additional_parameters(object_node,
				vla->array[vla->size - 1]) == ERROR)
			return (ERROR);
	}
	return (SUCCESS);
}
