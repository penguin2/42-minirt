/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_object_to_scene.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 19:28:24 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/08 21:08:32 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "message_parse.h"
#include "identifer_and_parameter.h"
#include "scene.h"
#include "define.h"
#include "utils.h"

static int	_check_number_of_required_objects(const t_json_node *master_node)
{
	if (get_list(master_node, ID_AMBIENT, 1) == NULL
		|| get_list(master_node, ID_CAMERA, 1) == NULL
		|| get_list(master_node, ID_SPOT, ACCEPT_1_OR_OVER) == NULL)
		return (ERROR);
	else
		return (SUCCESS);
}

int	json_object_to_scene(t_vla *json_object, t_scene *scene)
{
	const t_json_node	*master_node = json_object->array[0];
	int					success_or_error;

	ft_vla_init(&scene->objects);
	ft_vla_init(&scene->lights);
	success_or_error = ERROR;
	if (_check_number_of_required_objects(master_node) == ERROR)
		print_error(INVALID_REQUIRED_OBJECT);
	else if (camera_init(master_node, &scene->camera) == SUCCESS
		&& append_lights(master_node, &scene->lights) == SUCCESS
		&& append_objects(master_node, &scene->objects) == SUCCESS)
		success_or_error = SUCCESS;
	if (success_or_error == ERROR)
		scene_free(scene);
	return (success_or_error);
}
