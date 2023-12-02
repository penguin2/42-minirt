/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_generator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:47:16 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/02 14:30:02 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generator.h"
#include "object.h"
#include "triangle.h"
#include "identifer_and_parameter.h"

t_vla	*triangle_generator(t_object *object)
{
	const t_triangle	*triangle = object->ptr;
	t_vla				*json_triangle;

	json_triangle = ft_vla_new();
	ft_vla_append(json_triangle,
		vec3_to_json_list_node(&triangle->origin, VERTEX1));
	ft_vla_append(json_triangle,
		vec3_to_json_list_node(&triangle->edge[0], VERTEX2));
	ft_vla_append(json_triangle,
		vec3_to_json_list_node(&triangle->edge[1], VERTEX3));
	ft_vla_append(json_triangle,
		color_to_json_list_node(&object->color, COLORS));
	return (json_triangle);
}
