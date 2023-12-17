/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 19:48:58 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/17 20:03:53 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

static void	_merge(void **array, size_t size, void **tmp_array,
					bool (*cmp)(const void *, const void *))
{
	const size_t	mid = size / 2;
	size_t			idx;
	size_t			left_idx;
	size_t			right_idx;

	ft_memcpy(tmp_array, array, sizeof(void *) * size);
	idx = 0;
	left_idx = 0;
	right_idx = mid;
	while (left_idx < mid && right_idx < size)
	{
		if (cmp(tmp_array[left_idx], tmp_array[right_idx]))
			array[idx] = tmp_array[left_idx++];
		else
			array[idx] = tmp_array[right_idx++];
		idx++;
	}
	ft_memcpy(&array[idx], &tmp_array[left_idx],
		sizeof(void *) * (mid - left_idx));
	ft_memcpy(&array[idx], &tmp_array[right_idx],
		sizeof(void *) * (size - right_idx));
}

static void	_merge_sort(void **array, size_t size, void **tmp_array,
					bool (*cmp)(const void *, const void *))
{
	const size_t	mid = size / 2;

	if (size <= 1)
		return ;
	_merge_sort(array, mid, tmp_array, cmp);
	_merge_sort(&array[mid], size - mid, tmp_array, cmp);
	_merge(array, size, tmp_array, cmp);
}

void	ft_sort(void **array, size_t size,
				bool (*cmp)(const void *, const void *))
{
	void	**tmp_array;

	tmp_array = (void **)ft_xcalloc(size, sizeof(void *));
	_merge_sort(array, size, tmp_array, cmp);
	free(tmp_array);
}
