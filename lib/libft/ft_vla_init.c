/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vla_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:06:36 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/17 20:03:27 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_vla_init(t_vla *vla)
{
	vla->size = 0;
	vla->capacity = 1;
	vla->array = (void **)ft_xcalloc(vla->capacity, sizeof(void *));
}
