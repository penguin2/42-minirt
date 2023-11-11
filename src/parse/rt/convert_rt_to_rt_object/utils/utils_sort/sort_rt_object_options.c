/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rt_object_options.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:09:50 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/11 20:15:34 by rikeda           ###   ########.fr       */
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
