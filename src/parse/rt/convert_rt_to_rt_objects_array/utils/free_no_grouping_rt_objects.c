/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_no_grouping_rt_objects.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 21:31:18 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/24 16:30:02 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "libft.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

void	free_no_grouping_rt_objects(t_vla *no_grouping_rt_objects)
{
	size_t	idx;

	idx = 0;
	while (idx < no_grouping_rt_objects->size)
	{
		ft_vla_free(no_grouping_rt_objects->array[idx], ft_free_strings);
		free(no_grouping_rt_objects->array[idx]);
		idx++;
	}
	free(no_grouping_rt_objects->array);
}
