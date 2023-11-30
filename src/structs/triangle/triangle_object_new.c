/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_object_new.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 01:28:36 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/30 17:25:13 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "triangle.h"

t_object	*triangle_object_new(t_vec3 vertex[3])
{
	t_object	*new_object;

	new_object = object_new(triangle_new(vertex));
	new_object->get_color = triangle_get_color;
	new_object->get_dist = triangle_get_dist;
	new_object->get_normal = triangle_get_normal;
	new_object->get_id = triangle_get_id;
	new_object->free_ptr = triangle_free;
	return (new_object);
}
