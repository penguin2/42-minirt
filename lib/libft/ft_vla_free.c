/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vla_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:06:31 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/17 16:56:31 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_vla_free(t_vla *vla, void free_content(void *content))
{
	size_t	idx;

	idx = 0;
	while (idx < vla->size)
	{
		if (vla->array[idx] != NULL && free_content != NULL)
			free_content(vla->array[idx]);
		idx++;
	}
	free(vla->array);
}
