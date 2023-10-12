/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:35:18 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/12 16:49:56 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "material.h"
#include "object.h"
#include <stddef.h>

t_object	*object_new(
				void *ptr,
				void (*free_ptr)(void *ptr))
{
	t_object	*new;

	new = ft_xcalloc(1, sizeof(t_object));
	new->ptr = ptr;
	new->image_map = NULL;
	new->bump_map = NULL;
	new->material = material_create(1.0, 1.0, 1.0, 0.0);
	new->free_ptr = free_ptr;
	return (new);
}
