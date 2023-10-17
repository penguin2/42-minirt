/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vla_pop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:48:23 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/17 17:04:03 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_vla_pop(t_vla *vla)
{
	void	*ret;

	if (vla->size == 0)
		ret = NULL;
	else
	{
		vla->size -= 1;
		ret = vla->array[vla->size];
		vla->array[vla->size] = NULL;
	}
	return (ret);
}
