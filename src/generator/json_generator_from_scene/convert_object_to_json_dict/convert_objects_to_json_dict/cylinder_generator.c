/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_generator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:47:16 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/05 16:56:45 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generator.h"
#include "object.h"
#include "cylinder.h"
#include "identifer_and_parameter.h"

t_vla	*cylinder_generator(t_object *object)
{
	const t_cylinder	*cylinder = object->ptr;
	t_vla				*json_cylinder;

	json_cylinder = ft_vla_new();
	ft_vla_append(json_cylinder,
		vec3_to_json_list_node(&cylinder->center, COORDINATES));
	ft_vla_append(json_cylinder,
		vec3_to_json_list_node(&cylinder->system.axis_z, AXIS));
	ft_vla_append(json_cylinder,
		double_to_json_value_node(cylinder->radius * 2.0, DIAMETER));
	ft_vla_append(json_cylinder,
		double_to_json_value_node(cylinder->half_height * 2.0, HEIGHT));
	ft_vla_append(json_cylinder,
		color_to_json_list_node(&object->color, COLORS));
	append_material_parameters_node(json_cylinder, object->material);
	if (object->is_checkerboard)
		ft_vla_append(json_cylinder,
			bool_to_json_value_node(object->is_checkerboard, IS_CHECKERBOARD));
	return (json_cylinder);
}
