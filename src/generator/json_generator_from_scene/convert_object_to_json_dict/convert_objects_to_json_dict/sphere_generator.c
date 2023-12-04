/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_generator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:38:28 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/04 21:39:59 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generator.h"
#include "object.h"
#include "sphere.h"
#include "identifer_and_parameter.h"

t_vla	*sphere_generator(t_object *object)
{
	const t_sphere	*sphere = object->ptr;
	t_vla			*json_sphere;

	json_sphere = ft_vla_new();
	ft_vla_append(json_sphere,
		vec3_to_json_list_node(&sphere->center, COORDINATES));
	ft_vla_append(json_sphere,
		double_to_json_value_node(sphere->radius * 2.0, DIAMETER));
	ft_vla_append(json_sphere,
		color_to_json_list_node(&object->color, COLORS));
	append_material_parameters_node(json_sphere, object->material);
	if (object->is_checkerboard)
		ft_vla_append(json_sphere,
			bool_to_json_value_node(object->is_checkerboard, IS_CHECKERBOARD));
	return (json_sphere);
}
