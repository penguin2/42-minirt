/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rt_objects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 18:42:45 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/09 20:17:27 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include <stdbool.h>
#include <stddef.h>

static size_t	_get_smallest_object_idx(t_vla *rt_objects, size_t idx)
{
	size_t		smallest_idx;
	const char	*identifer;
	const char	*smallest_identifer;

	smallest_idx = idx;
	smallest_identifer = get_identifer_from_rt_objects(rt_objects, idx++);
	while (idx < rt_objects->size)
	{
		identifer = get_identifer_from_rt_objects(rt_objects, idx);
		if (0 < ft_strcmp(smallest_identifer, identifer))
		{
			smallest_idx = idx;
			smallest_identifer = identifer;
		}
		idx++;
	}
	return (smallest_idx);
}

void	sort_rt_objects(t_vla *rt_objects)
{
	ft_vla_sort(rt_objects, _get_smallest_object_idx);
}
