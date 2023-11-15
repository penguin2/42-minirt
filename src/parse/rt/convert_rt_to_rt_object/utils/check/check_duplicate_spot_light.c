/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicate_spot_light.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:14:33 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/16 17:33:21 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "libft.h"
#include "parse.h"
#include "identifer_and_parameter.h"
#include <stddef.h>

int	check_duplicate_spot_light(t_vla *rt_objects)
{
	size_t		idx;
	const char	*identifer;
	t_vla		*rt_object;

	if (MODE != MODE_MANDATORY)
		return (SUCCESS);
	idx = 0;
	while (idx < rt_objects->size)
	{
		rt_object = rt_objects->array[idx];
		identifer = get_identifer_from_rt_objects(rt_object, 0);
		if (ft_is_equal_str(identifer, ID_SPOT))
		{
			if (rt_object->size <= 1)
				return (SUCCESS);
			else
				return (ERROR);
		}
		idx++;
	}
	return (SUCCESS);
}
