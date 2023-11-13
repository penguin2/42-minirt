/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vla_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:16:38 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/13 14:12:35 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	_swap(const t_vla *vla, size_t idx1, size_t idx2)
{
	t_vla	*tmp;

	tmp = vla->array[idx1];
	vla->array[idx1] = vla->array[idx2];
	vla->array[idx2] = tmp;
}

/**
* @brief Sort the contents of the VLA.
*		 The sorting algorithm is selection sort.
*
* @param vla VLA with some contents
* @param get_smallest Function pointer
*					  that returns the index of the smallest value
*					  among the elements after
*					  the index specified by second argument in
*					  the VLA specified by the first argument
*/
void	ft_vla_sort(const t_vla *vla,
			size_t (*get_smallest)(const t_vla *, size_t))
{
	size_t	idx;
	size_t	smallest_idx;

	if (vla->size <= 1)
		return ;
	idx = 0;
	while (idx < vla->size - 1)
	{
		smallest_idx = get_smallest(vla, idx);
		if (idx != smallest_idx)
			_swap(vla, idx, smallest_idx);
		idx++;
	}
}
