/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_generator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:43:47 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/06 19:29:41 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generator.h"
#include "object.h"
#include "plane.h"
#include "identifer_and_parameter.h"

t_vla	*plane_generator(t_object *object)
{
	const t_plane	*plane = object->ptr;
	t_vla			*json_plane;

	json_plane = ft_vla_new();
	ft_vla_append(json_plane,
		vec3_to_json_list_node(&plane->origin, COORDINATES));
	ft_vla_append(json_plane,
		vec3_to_json_list_node(&plane->system.axis_z, NORMAL));
	ft_vla_append(json_plane,
		color_to_json_list_node(&object->color, COLORS));
	append_material_parameters_node(json_plane, object->material);
	if (object->is_checkerboard)
		ft_vla_append(json_plane,
			bool_to_json_value_node(object->is_checkerboard, IS_CHECKERBOARD));
	append_ppm_reader(json_plane, object->texture_map, TEXTURE_MAP);
	append_ppm_reader(json_plane, object->bump_map, BUMP_MAP);
	return (json_plane);
}
