/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_generator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:47:16 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/30 16:52:49 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generator.h"
#include "libft.h"
#include "object.h"
#include "triangle.h"
#include "identifer_and_parameter.h"

t_vla	*triangle_generator(t_object *object)
{
	const t_triangle	*triangle = object->ptr;
	t_vla				*json_triangle_object;

	json_triangle_object = ft_vla_new();
	ft_vla_append(json_triangle_object,
		vec3_to_json_list(&triangle->origin, VERTEX1));
	ft_vla_append(json_triangle_object,
		vec3_to_json_list(&triangle->edge[0], VERTEX2));
	ft_vla_append(json_triangle_object,
		vec3_to_json_list(&triangle->edge[1], VERTEX3));
	ft_vla_append(json_triangle_object,
		color_to_json_list(&object->color, COLORS));
	return (json_triangle_object);
}
