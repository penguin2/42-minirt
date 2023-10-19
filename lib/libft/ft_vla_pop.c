/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vla_pop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:48:23 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/19 20:29:05 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	_vla_rearrange_array(t_vla *vla, size_t idx)
{
	void	**array;
	size_t	move_size;

	array = vla->array;
	move_size = sizeof(void *) * (vla->size - idx - 1);
	if (move_size != 0)
		ft_memcpy(&array[idx], &array[idx + 1], move_size);
}

void	*ft_vla_pop(t_vla *vla, size_t idx)
{
	void	*ret;

	if (vla->size == 0 || vla->size <= idx)
		return (NULL);
	ret = vla->array[idx];
	_vla_rearrange_array(vla, idx);
	vla->size -= 1;
	vla->array[vla->size] = NULL;
	return (ret);
}
