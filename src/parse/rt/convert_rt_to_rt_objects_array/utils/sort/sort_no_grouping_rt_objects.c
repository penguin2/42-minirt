/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_no_grouping_rt_objects.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 18:42:45 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/30 14:28:26 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include <stdbool.h>
#include <stddef.h>

static bool	_cmp_identifer(const void *ptr1, const void *ptr2)
{
	const char	**strings1 = ((t_vla *)ptr1)->array[0];
	const char	**strings2 = ((t_vla *)ptr2)->array[0];
	const char	*identifer1 = strings1[IDENTIFER_IDX];
	const char	*identifer2 = strings2[IDENTIFER_IDX];

	return (ft_strcmp(identifer1, identifer2) < 0);
}

void	sort_no_grouping_rt_objects(t_vla *no_grouping_rt_objects)
{
	ft_sort(
		no_grouping_rt_objects->array,
		no_grouping_rt_objects->size,
		_cmp_identifer
		);
}
