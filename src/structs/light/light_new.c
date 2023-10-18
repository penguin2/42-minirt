/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:53:12 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/12 16:54:56 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "light.h"

t_light	*light_new(
			void *ptr,
			void (*free_ptr)(void *ptr))
{
	t_light	*new;

	new = ft_xcalloc(1, sizeof(t_light));
	new->ptr = ptr;
	new->free_ptr = free_ptr;
	return (new);
}
