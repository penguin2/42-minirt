/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_object_new.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 01:19:55 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/30 17:21:07 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sphere.h"

t_object	*sphere_object_new(t_vec3 center, double radius)
{
	t_object	*new_object;

	new_object = object_new(sphere_new(center, radius));
	new_object->get_color = sphere_get_color;
	new_object->get_dist = sphere_get_dist;
	new_object->get_normal = sphere_get_normal;
	new_object->get_id = sphere_get_id;
	new_object->free_ptr = sphere_free;
	return (new_object);
}
