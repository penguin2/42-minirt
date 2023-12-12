/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_get_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 01:21:21 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/27 10:05:18 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit.h"
#include "ppm_reader.h"
#include "sphere.h"

t_color	sphere_get_color(const t_object *object, const t_hit *hit)
{
	if (object->is_checkerboard)
		return (sphere_get_checkerboard_color(object->ptr, hit->pos));
	if (object->texture_map != NULL)
		return (sphere_get_texture_color(
				object->ptr, object->texture_map, hit->pos));
	return (object->color);
}
