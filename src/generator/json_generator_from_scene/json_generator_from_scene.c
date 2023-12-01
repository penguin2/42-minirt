/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_generator_from_scene.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:52:27 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/01 18:33:19 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generator.h"
#include "define.h"
#include "identifer_and_parameter.h"

t_vla	*json_generator_from_scene(t_scene *scene, int fd)
{
	t_vla		*json_object;
	t_vla		*dict;

	json_object = ft_vla_new();
	dict = ft_vla_new();
	ft_vla_append(json_object, json_node_new(NULL, dict, NODE_DICT));
	json_dict_generator_from_camera(&scene->camera, dict);
	json_dict_generator_from_lights(&scene->lights, dict);
	json_dict_generator_from_objects(&scene->objects, dict);
	json_generator_from_json_object(json_object->array[0], 0, fd);
	free_json_object(json_object);
	return (SUCCESS);
}
