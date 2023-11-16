/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadric_object_new.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 01:25:08 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/17 01:26:52 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quadric.h"

t_object	*quadric_object_new(
				t_vec3 center,
				double coeff[QUADRIC_COEFFICIENT_SIZE])
{
	t_object	*new_object;

	new_object = object_new(quadric_new(center, coeff));
	new_object->get_color = quadric_get_color;
	new_object->get_dist = quadric_get_dist;
	new_object->get_normal = quadric_get_normal;
	new_object->free_ptr = quadric_free;
	return (new_object);
}
