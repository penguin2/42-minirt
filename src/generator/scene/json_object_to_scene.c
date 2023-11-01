/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_object_to_scene.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 19:28:24 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/01 17:32:29 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generator.h"
#include "libft.h"
#include "parse.h"
#include "scene.h"
#include "define.h"
#include <stddef.h>

static int	_check_number_of_required_objects(const t_json_node *master_node)
{
	if (get_list(master_node, ID_AMBIENT, 1) == NULL
		|| get_list(master_node, ID_CAMERA, 1) == NULL
		|| get_list(master_node, ID_SPOT, 1) == NULL)
		return (ERROR);
	else
		return (SUCCESS);
}

int	json_object_to_scene(t_vla *json_object, t_scene *scene)
{
	const t_json_node	*master_node = json_object->array[0];

	if (_check_number_of_required_objects(master_node) == ERROR)
		return (ERROR);
	else if (camera_init(master_node, &scene->camera) == ERROR
		|| append_lights(master_node, &scene->lights) == ERROR
		|| append_objects(master_node, &scene->objects) == ERROR)
		return (ERROR);
	else
		return (SUCCESS);
}
