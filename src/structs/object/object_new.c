/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:35:18 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/25 15:51:45 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "material.h"
#include "object.h"
#include <stddef.h>

t_object	*object_new(void *ptr)
{
	t_object	*new;

	new = ft_xcalloc(1, sizeof(t_object));
	new->ptr = ptr;
	new->is_checkerboard = false;
	new->texture_map = NULL;
	new->bump_map = NULL;
	new->color = color_white();
	new->material = material_create();
	return (new);
}
