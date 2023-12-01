/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_json_object.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:04:28 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/01 17:28:59 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include <stdbool.h>
#include <stddef.h>

bool	_cmp_dict_key(const void *ptr1, const void *ptr2)
{
	const t_json_node	*node1 = (const t_json_node *)ptr1;
	const t_json_node	*node2 = (const t_json_node *)ptr2;
	const char			*key1 = (const char *)node1->key;
	const char			*key2 = (const char *)node2->key;

	return (ft_strcmp(key1, key2) < 0);
}

void	sort_json_object(t_json_node *master_node)
{
	t_vla	*vla;
	size_t	idx;

	if (master_node->type == NODE_VALUE)
		return ;
	vla = master_node->value;
	if (master_node->type == NODE_DICT)
		ft_sort(vla->array, vla->size, _cmp_dict_key);
	idx = 0;
	while (idx < vla->size)
		sort_json_object(vla->array[idx++]);
}
