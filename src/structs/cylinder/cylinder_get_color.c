/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_get_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 01:34:19 by taekklee          #+#    #+#             */
/*   Updated: 2023/12/01 17:19:18 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"
#include "hit.h"

t_color	cylinder_get_color(const t_object *object, const t_hit *hit)
{
	if (object->is_checkerboard)
		return (cylinder_get_checkerboard_color(object->ptr, hit->pos));
	if (object->texture_map != NULL)
		return (cylinder_get_texture_color(
				object->ptr, object->texture_map, hit->pos));
	return (object->color);
}
