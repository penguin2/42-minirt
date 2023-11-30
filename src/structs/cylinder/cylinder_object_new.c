/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_object_new.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 01:33:01 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/30 17:23:36 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"

t_object	*cylinder_object_new(
				t_vec3 center,
				t_vec3 dir,
				double radius,
				double half_height)
{
	t_object	*new_object;

	new_object = object_new(cylinder_new(center, dir, radius, half_height));
	new_object->get_color = cylinder_get_color;
	new_object->get_dist = cylinder_get_dist;
	new_object->get_normal = cylinder_get_normal;
	new_object->get_id = cylinder_get_id;
	new_object->free_ptr = cylinder_free;
	return (new_object);
}
