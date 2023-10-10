/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vla_append.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:06:26 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/10 20:06:27 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_vla_append(t_vla *vla, void *content)
{
	void	**tmp;

	if (vla->size == vla->capacity)
	{
		if ((SIZE_MAX / 2) < vla->capacity)
		{
			ft_putendl_fd(ERR_VLA_APPEND, STDERR_FILENO);
			exit(EXIT_FAILURE);
		}
		vla->capacity *= 2;
		tmp = (void **)ft_xcalloc(sizeof(void *), vla->capacity);
		ft_memcpy(tmp, vla->array, sizeof(void *) * vla->size);
		free(vla->array);
		vla->array = tmp;
	}
	vla->array[vla->size++] = content;
}
