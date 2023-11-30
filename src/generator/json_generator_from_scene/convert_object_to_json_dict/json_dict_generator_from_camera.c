/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_dict_generator_from_camera.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:15:57 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/30 19:47:50 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "generator.h"
#include "identifer_and_parameter.h"
#include "define.h"
#include "parse.h"

static t_vla	*_camera_generator(t_camera *camera)
{
	t_vla	*json_camera_object;

	json_camera_object = ft_vla_new();
	ft_vla_append(json_camera_object,
		vec3_to_json_list(&camera->eye, COORDINATES));
	ft_vla_append(json_camera_object,
		vec3_to_json_list(&camera->dir, DIRECTION));
	ft_vla_append(json_camera_object,
		double_to_json_list(camera->fov / (2.0 * PI / 360.0), FOV));
	return (json_camera_object);
}

t_json_node	*_convert_camera_to_camera_dict(t_camera *camera)
{
	t_json_node	*camera_dict;

	camera_dict = json_node_new(ft_strdup(ID_CAMERA), ft_vla_new(), NODE_LIST);
	ft_vla_append(
		camera_dict->value,
		json_node_new(
			NULL,
			_camera_generator(camera),
			NODE_DICT)
		);
	return (camera_dict);
}

void	json_dict_generator_from_camera(t_camera *camera, t_vla *dict)
{
	t_json_node	*camera_json_node;

	camera_json_node = _convert_camera_to_camera_dict(camera);
	if (camera_json_node != NULL)
		ft_vla_append(dict, camera_json_node);
}
