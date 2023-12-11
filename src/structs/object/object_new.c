/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:35:18 by taekklee          #+#    #+#             */
/*   Updated: 2023/12/11 11:21:21 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "material.h"
#include "material_box.h"
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
	material_box_init(&new->material_box);
	return (new);
}
