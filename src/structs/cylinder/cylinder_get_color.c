/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_get_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 01:34:19 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/17 02:11:06 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"
#include "hit.h"

t_color	cylinder_get_color(const t_object *object, const t_hit *hit)
{
	if (object->is_checkerboard)
		return (cylinder_get_checkerboard_color(object->ptr, hit->pos));
	return (object->color);
}
