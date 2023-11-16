/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_get_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 01:21:21 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/17 02:10:21 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit.h"
#include "sphere.h"

t_color	sphere_get_color(const t_object *object, const t_hit *hit)
{
	if (object->is_checkerboard)
		return (sphere_get_checkerboard_color(object->ptr, hit->pos));
	return (object->color);
}
