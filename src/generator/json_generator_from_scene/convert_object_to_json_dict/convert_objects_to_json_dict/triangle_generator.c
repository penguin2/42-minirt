/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_generator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:47:16 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/04 21:40:06 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generator.h"
#include "libvec3.h"
#include "object.h"
#include "triangle.h"
#include "identifer_and_parameter.h"

t_vla	*triangle_generator(t_object *object)
{
	const t_triangle	*triangle = object->ptr;
	const t_vec3		vertex2 = vec3_add(triangle->origin, triangle->edge[0]);
	const t_vec3		vertex3 = vec3_add(triangle->origin, triangle->edge[1]);
	t_vla				*json_triangle;

	json_triangle = ft_vla_new();
	ft_vla_append(json_triangle,
		vec3_to_json_list_node(&triangle->origin, VERTEX1));
	ft_vla_append(json_triangle,
		vec3_to_json_list_node(&vertex2, VERTEX2));
	ft_vla_append(json_triangle,
		vec3_to_json_list_node(&vertex3, VERTEX3));
	ft_vla_append(json_triangle,
		color_to_json_list_node(&object->color, COLORS));
	append_material_parameters_node(json_triangle, object->material);
	return (json_triangle);
}
