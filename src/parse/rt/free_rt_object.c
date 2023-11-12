/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_rt_object.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 21:31:18 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/12 21:33:38 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "libft.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

void	free_rt_object(t_vla *rt_object, bool one_step_deep)
{
	size_t	idx;

	idx = 0;
	while (idx < rt_object->size)
	{
		if (one_step_deep)
			free_rt_object(rt_object->array[idx], false);
		else
			ft_vla_free(rt_object->array[idx], ft_free_strings);
		free(rt_object->array[idx]);
		idx++;
	}
	free(rt_object->array);
}
