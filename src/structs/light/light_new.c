/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:53:12 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/24 02:03:31 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "light.h"

t_light	*light_new(void *ptr)
{
	t_light	*new;

	new = ft_xcalloc(1, sizeof(t_light));
	new->ptr = ptr;
	new->color = color_white();
	return (new);
}
