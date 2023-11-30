/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_dict_generator_from_objects.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:35:01 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/30 20:00:22 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generator.h"
#include "identifer_and_parameter.h"

void	json_dict_generator_from_objects(t_vla *objects, t_vla *dict)
{
	t_json_node	*object_json_node;

	object_json_node = convert_objects_to_json_dict(
			objects, ID_SPHERE, OBJECT_ID_SPHERE, sphere_generator);
	if (object_json_node != NULL)
		ft_vla_append(dict, object_json_node);
	object_json_node = convert_objects_to_json_dict(
			objects, ID_PLANE, OBJECT_ID_PLANE, plane_generator);
	if (object_json_node != NULL)
		ft_vla_append(dict, object_json_node);
	object_json_node = convert_objects_to_json_dict(
			objects, ID_CYLINDER, OBJECT_ID_CYLINDER, cylinder_generator);
	if (object_json_node != NULL)
		ft_vla_append(dict, object_json_node);
	object_json_node = convert_objects_to_json_dict(
			objects, ID_TRIANGLE, OBJECT_ID_TRIANGLE, triangle_generator);
	if (object_json_node != NULL)
		ft_vla_append(dict, object_json_node);
	object_json_node = convert_objects_to_json_dict(
			objects, ID_QUADRIC, OBJECT_ID_QUADRIC, quadric_generator);
	if (object_json_node != NULL)
		ft_vla_append(dict, object_json_node);
}
