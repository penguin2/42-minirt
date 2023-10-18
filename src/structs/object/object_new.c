/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:35:18 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/18 11:02:49 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "material.h"
#include "object.h"
#include <stddef.h>

t_object	*object_new(
					void *ptr,
					t_fn_get_dist get_dist,
					t_fn_get_normal get_normal,
					t_fn_free_ptr free_ptr)
{
	t_object	*new;

	new = ft_xcalloc(1, sizeof(t_object));
	new->ptr = ptr;
	new->image_map = NULL;
	new->bump_map = NULL;
	new->material = material_create(1.0, 1.0, 1.0, 0.0);
	new->get_dist = get_dist;
	new->get_normal = get_normal;
	new->free_ptr = free_ptr;
	return (new);
}
