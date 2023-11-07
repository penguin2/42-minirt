/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:53:12 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/02 01:26:49 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "light.h"

t_light	*light_new(
			void *ptr,
			t_fn_get_color get_color,
			t_fn_free_light free_light)
{
	t_light	*new;

	new = ft_xcalloc(1, sizeof(t_light));
	new->ptr = ptr;
	new->get_color = get_color;
	new->free_light = free_light;
	return (new);
}
