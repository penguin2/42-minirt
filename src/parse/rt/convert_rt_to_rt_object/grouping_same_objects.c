/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grouping_same_objects.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:41:13 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/17 17:43:05 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include <stddef.h>

/**
* @brief Create a new vla between vla
*		 and vla of rt_objects structure and insert it.
*
* @param rt_objects vla with string as content vla with string as content.
* @param idx Index of the vla where the object you want to summarize
*			 the identifer in rt_objects is stored.
*/
static void	_prepere_rt_object(t_vla *rt_objects, size_t idx)
{
	t_vla	*tmp_rt_object;

	tmp_rt_object = rt_objects->array[idx];
	rt_objects->array[idx] = ft_vla_new();
	ft_vla_append(rt_objects->array[idx], tmp_rt_object);
}

/**
* @brief rt_objects is interspersed with vla, a grouping of objects
*		 with the same identifer.
*
* @param rt_objects vla with string as content vla with string as content.
*/
void	grouping_same_objects(t_vla *rt_objects)
{
	size_t		idx;
	const char	*identifer;
	const char	*prev_identifer;
	t_vla		*rt_object;

	idx = 0;
	prev_identifer = NULL;
	while (idx < rt_objects->size)
	{
		identifer = get_identifer_from_rt_objects(rt_objects, idx);
		if (is_dupulicate(prev_identifer, identifer))
		{
			rt_object = ft_vla_pop(rt_objects, idx);
			ft_vla_append(rt_objects->array[idx - 1], rt_object);
		}
		else
			_prepere_rt_object(rt_objects, idx++);
		prev_identifer = identifer;
	}
}
