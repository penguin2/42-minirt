/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicate_spot.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:19:52 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/24 18:19:27 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "parse.h"
#include "identifer_and_parameter.h"
#include "utils.h"
#include "message_parse.h"
#include <stddef.h>

int	check_duplicate_spot(t_vla *rt_objects)
{
	size_t		idx;
	const char	*identifer;
	t_vla		*rt_object;

	idx = 0;
	while (idx < rt_objects->size)
	{
		identifer = get_identifer_from_rt_objects(rt_objects, idx);
		rt_object = rt_objects->array[idx];
		if (ft_is_equal_str(identifer, ID_SPOT))
		{
			if (rt_object->size <= 1)
				return (SUCCESS);
			else
			{
				print_error(SPOT_LIGHT_DUPLICATE);
				return (ERROR);
			}
		}
		idx++;
	}
	return (SUCCESS);
}
