/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_object_new.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 01:19:55 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/17 01:21:05 by taekklee         ###   ########.fr       */
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
	new_object->free_ptr = sphere_free;
	return (new_object);
}
