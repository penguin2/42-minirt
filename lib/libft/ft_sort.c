/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 19:48:58 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/30 14:41:11 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

static void	**_copy_array(void **array, size_t size)
{
	void	**new_array;
	size_t	idx;

	new_array = (void **)ft_xcalloc(sizeof(void *), size);
	idx = 0;
	while (idx < size)
	{
		new_array[idx] = array[idx];
		idx++;
	}
	return (new_array);
}

static void	_merge(void **array, size_t left, size_t right,
					bool (*cmp)(const void *, const void *))
{
	void			**tmp_array;
	const size_t	mid_idx_of_tmp_array = (right - left) / 2;
	size_t			idx;
	size_t			left_idx;
	size_t			right_idx;

	tmp_array = _copy_array(&array[left], (right - left));
	left_idx = 0;
	right_idx = mid_idx_of_tmp_array;
	idx = left;
	while (left_idx < mid_idx_of_tmp_array && right_idx < (right - left))
	{
		if (cmp(tmp_array[left_idx], tmp_array[right_idx]))
			array[idx] = tmp_array[left_idx++];
		else
			array[idx] = tmp_array[right_idx++];
		idx++;
	}
	ft_memcpy(&array[idx], &tmp_array[left_idx],
		sizeof(void *) * (mid_idx_of_tmp_array - left_idx));
	ft_memcpy(&array[idx], &tmp_array[right_idx],
		sizeof(void *) * (right - left - right_idx));
	free(tmp_array);
}

static void	_merge_sort(void **array, size_t left, size_t right,
					bool (*cmp)(const void *, const void *))
{
	const size_t	mid = (right + left) / 2;

	if (left + 1 < right)
	{
		_merge_sort(array, left, mid, cmp);
		_merge_sort(array, mid, right, cmp);
		_merge(array, left, right, cmp);
	}
}

void	ft_sort(void **array, size_t size,
				bool (*cmp)(const void *, const void *))
{
	_merge_sort(array, 0, size, cmp);
}
