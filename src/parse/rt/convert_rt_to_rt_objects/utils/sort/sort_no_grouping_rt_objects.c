/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_no_grouping_rt_objects.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 18:42:45 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/24 18:03:09 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include <stdbool.h>
#include <stddef.h>

/**
* @brief Find the index that contains the smallest value of rt_objects
*		 in ascii order from the identifer in rt_objects.
*
* @param no_grouping_rt_objects vla of rt_object
* @param idx Index to start scanning when looking for the smallest value
*			 from the VLA. Find the index that contains the smallest value
*			 from this index to rt_object->size.
*
* @return Index storing the smallest value in rt_objects.
*/
static size_t	_get_smallest_object_idx(const t_vla *no_grouping_rt_objects,
											size_t idx)
{
	size_t		smallest_idx;
	const char	*identifer;
	const char	*smallest_identifer;

	smallest_idx = idx;
	smallest_identifer = get_identifer_from_no_grouping_rt_objects(
			no_grouping_rt_objects, idx++);
	while (idx < no_grouping_rt_objects->size)
	{
		identifer = get_identifer_from_no_grouping_rt_objects(
				no_grouping_rt_objects, idx);
		if (0 < ft_strcmp(smallest_identifer, identifer))
		{
			smallest_idx = idx;
			smallest_identifer = identifer;
		}
		idx++;
	}
	return (smallest_idx);
}

void	sort_no_grouping_rt_objects(t_vla *no_grouping_rt_objects)
{
	ft_vla_sort(no_grouping_rt_objects, _get_smallest_object_idx);
}
