/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_object_new.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 01:15:15 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/30 17:22:23 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "plane.h"

t_object	*plane_object_new(t_vec3 origin, t_vec3 normal)
{
	t_object	*new_object;

	new_object = object_new(plane_new(origin, normal));
	new_object->get_color = plane_get_color;
	new_object->get_dist = plane_get_dist;
	new_object->get_normal = plane_get_normal;
	new_object->get_id = plane_get_id;
	new_object->free_ptr = plane_free;
	return (new_object);
}
