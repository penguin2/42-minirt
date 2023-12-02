/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_generator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:47:16 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/02 14:29:13 by rikeda           ###   ########.fr       */
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
		vec3_to_json_list_node(&cylinder->dir, AXIS));
	ft_vla_append(json_cylinder,
		double_to_json_value_node(cylinder->radius * 2.0, DIAMETER));
	ft_vla_append(json_cylinder,
		double_to_json_value_node(cylinder->half_height * 2.0, HEIGHT));
	ft_vla_append(json_cylinder,
		color_to_json_list_node(&object->color, COLORS));
	return (json_cylinder);
}
