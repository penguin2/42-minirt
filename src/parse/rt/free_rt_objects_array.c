/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_rt_objects_array.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 21:31:18 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/24 19:21:38 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "libft.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

void	_free_rt_objects(t_vla *rt_objects)
{
	size_t	idx;

	idx = 0;
	while (idx < rt_objects->size)
	{
		ft_vla_free(rt_objects->array[idx], ft_free_strings);
		free(rt_objects->array[idx]);
		idx++;
	}
	free(rt_objects->array);
}

void	free_rt_objects_array(t_vla *rt_objects_array)
{
	size_t	idx;

	idx = 0;
	while (idx < rt_objects_array->size)
	{
		_free_rt_objects(rt_objects_array->array[idx]);
		free(rt_objects_array->array[idx]);
		idx++;
	}
	free(rt_objects_array->array);
}
