/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grouping_same_rt_objects.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:41:13 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/24 18:03:56 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include <stddef.h>

/**
* @brief Group rt_objects with the same identifer into one VLA.
*
* @param no_grouping_rt_objects VLA of ungrouped rt_object.
*/
void	grouping_same_rt_objects(t_vla *no_grouping_rt_objects)
{
	size_t		idx;
	size_t		group_count;
	const char	*identifer;
	const char	*prev_identifer;
	t_vla		*tmp;

	prev_identifer = NULL;
	group_count = 0;
	idx = 0;
	while (idx < no_grouping_rt_objects->size)
	{
		identifer = get_identifer_from_no_grouping_rt_objects(
				no_grouping_rt_objects, idx);
		tmp = no_grouping_rt_objects->array[idx];
		if (!is_dupulicate(prev_identifer, identifer))
			no_grouping_rt_objects->array[group_count++] = ft_vla_new();
		ft_vla_append(no_grouping_rt_objects->array[group_count - 1], tmp);
		prev_identifer = identifer;
		idx++;
	}
	no_grouping_rt_objects->size = group_count;
}
