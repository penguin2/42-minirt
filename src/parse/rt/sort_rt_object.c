/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rt_object.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 18:42:45 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/05 20:22:57 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include "define.h"
#include <stdbool.h>
#include <stddef.h>

static void	_swap_rt_object(t_vla *rt_objects, size_t idx1, size_t idx2)
{
	t_vla	*tmp_object;

	tmp_object = rt_objects->array[idx1];
	rt_objects->array[idx1] = rt_objects->array[idx2];
	rt_objects->array[idx2] = tmp_object;
}

static size_t	_get_smallest_object_idx(t_vla *rt_objects, size_t idx)
{
	size_t	smallest_object_idx;
	t_vla	*rt_object;
	char	*smallest_object_identifer;

	smallest_object_idx = idx;
	rt_object = rt_objects->array[idx];
	smallest_object_identifer = rt_object->array[0];
	idx++;
	while (idx < rt_objects->size)
	{
		rt_object = rt_objects->array[idx];
		if (0 < ft_strcmp(smallest_object_identifer, rt_object->array[0]))
		{
			smallest_object_identifer = rt_object->array[0];
			smallest_object_idx = idx;
		}
		idx++;
	}
	return (smallest_object_idx);
}

int	sort_rt_object(t_vla *rt_objects)
{
	size_t	idx;
	size_t	smallest_object_idx;

	idx = 0;
	while (idx < rt_objects->size)
	{
		smallest_object_idx = _get_smallest_object_idx(rt_objects, idx);
		_swap_rt_object(rt_objects, idx, smallest_object_idx);
		idx++;
	}
	return (SUCCESS);
}
