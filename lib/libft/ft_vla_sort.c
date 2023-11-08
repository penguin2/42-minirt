/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vla_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:16:38 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/09 16:25:56 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	_swap(t_vla *vla, size_t idx1, size_t idx2)
{
	t_vla	*tmp;

	tmp = vla->array[idx1];
	vla->array[idx1] = vla->array[idx2];
	vla->array[idx2] = tmp;
}

void	ft_vla_sort(t_vla *vla, size_t (*get_smallest)(t_vla *, size_t))
{
	size_t	idx;
	size_t	smallest_idx;

	idx = 0;
	while (idx < vla->size)
	{
		smallest_idx = get_smallest(vla, idx);
		if (idx != smallest_idx)
			_swap(vla, idx, smallest_idx);
		idx++;
	}
}
