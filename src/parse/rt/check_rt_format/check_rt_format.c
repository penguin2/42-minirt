/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rt_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 19:32:27 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/05 20:00:46 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include "generator.h"
#include "define.h"
#include <stddef.h>

int	check_rt_format(t_vla *rt_objects)
{
	size_t	idx;
	t_vla	*rt_object;

	idx = 0;
	while (idx < rt_objects->size)
	{
		rt_object = rt_objects->array[idx];
		if (check_rt_object(rt_object) == ERROR)
			return (ERROR);
	}
	return (SUCCESS);
}
