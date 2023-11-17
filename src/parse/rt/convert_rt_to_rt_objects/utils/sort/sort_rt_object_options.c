/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rt_object_options.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:09:50 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/17 18:41:01 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include <stddef.h>

static const char	*_get_option_key(const t_vla *rt_object, size_t idx)
{
	const char	**strings = rt_object->array[idx];

	return (strings[1]);
}

/**
* @brief Obtain the index of the VLA in which the parameter of
*		 the object with the lowest value is stored.
*		 The 0th index of rt_object is not optional,
*		 but contains a required parameter, so if idx == 0, return 0
*		 and does not change the order.
*
* @param rt_object vla of required parameters and optional parameters.
* @param idx Index to start scanning when looking for the smallest value
*			 from the VLA. Find the index that contains the smallest value
*			 from this index to rt_object->size.
*
* @return Index storing the smallest value in rt_object.
*/
static size_t	_get_smallest_option(const t_vla *rt_object, size_t idx)
{
	size_t		smallest_idx;
	const char	*smallest_option;

	if (idx == 0)
		return (0);
	smallest_idx = idx;
	smallest_option = _get_option_key(rt_object, idx++);
	while (idx < rt_object->size)
	{
		if (0 < ft_strcmp(smallest_option, _get_option_key(rt_object, idx)))
		{
			smallest_option = _get_option_key(rt_object, idx);
			smallest_idx = idx;
		}
		idx++;
	}
	return (smallest_idx);
}

void	sort_rt_object_options(const t_vla *rt_object)
{
	ft_vla_sort(rt_object, _get_smallest_option);
}
