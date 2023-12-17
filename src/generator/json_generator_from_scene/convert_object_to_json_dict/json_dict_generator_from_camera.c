/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_dict_generator_from_camera.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:15:57 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/15 16:51:42 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generator.h"
#include "identifer_and_parameter.h"
#include "define.h"
#include <math.h>

static t_vla	*_json_camera_generator(t_camera *camera)
{
	t_vla	*json_camera;

	json_camera = ft_vla_new();
	ft_vla_append(json_camera,
		vec3_to_json_list_node(&camera->eye, COORDINATES));
	ft_vla_append(json_camera,
		vec3_to_json_list_node(&camera->dir, DIRECTION));
	ft_vla_append(json_camera,
		double_to_json_value_node(round(camera->fov / DEG_TO_RAD), FOV));
	return (json_camera);
}

t_json_node	*_convert_camera_to_camera_dict(t_camera *camera)
{
	t_json_node	*json_camera_dict;

	json_camera_dict = json_node_new(
			ft_strdup(ID_CAMERA), ft_vla_new(), NODE_LIST);
	ft_vla_append(json_camera_dict->value,
		json_node_new(NULL, _json_camera_generator(camera), NODE_DICT));
	return (json_camera_dict);
}

void	json_dict_generator_from_camera(t_camera *camera, t_vla *dict)
{
	t_json_node	*json_camera_dict;

	json_camera_dict = _convert_camera_to_camera_dict(camera);
	if (json_camera_dict != NULL)
		ft_vla_append(dict, json_camera_dict);
}
