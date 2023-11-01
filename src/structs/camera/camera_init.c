/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:08:04 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/27 02:48:53 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "define.h"
#include "utils.h"
#include <stdbool.h>

static t_vec3	_get_camera_up_vector(t_vec3 dir);
static void		_set_camera_infomation(t_camera *camera, double fov);

int	camera_init(const t_json_node *node, t_camera *camera)
{
	const t_vla			*object_list = get_list(node, ID_CAMERA, 1);
	const t_json_node	*object = object_list->array[0];
	double				fov;

	if (object->type != NODE_DICT)
		return (ERROR);
	if (json_node_to_double(select_json_node(object, FOV),
			&fov, 0, 180) == ERROR
		|| list_to_vec3(get_list(object, COORDINATES, 3),
			&camera->eye, UNLIMITED, UNLIMITED) == ERROR
		|| list_to_vec3(get_list(object, DIRECTION, 3),
			&camera->dir, -1, 1) == ERROR)
		return (ERROR);
	_set_camera_infomation(camera, fov);
	return (SUCCESS);
}

static void	_set_camera_infomation(t_camera *camera, double fov)
{
	camera->dir = vec3_unit(camera->dir);
	camera->fov = fov * (2.0 * PI / 360);
	camera->up = _get_camera_up_vector(camera->dir);
	camera->right = vec3_cross(camera->dir, camera->up);
	camera->fov = FOV_DEFAULT * DEG_TO_RAD;
	camera_set_viewport(camera, &camera->viewport);
	return (SUCCESS);
}

// suppose dir is a unit vector
static t_vec3	_get_camera_up_vector(t_vec3 dir)
{
	t_vec3	head;

	if (is_zero(1.0 - vec3_dot(vec3_create(0, 1, 0), dir)))
		head = vec3_create(0, 0, 1);
	else if (is_zero(-1.0 - vec3_dot(vec3_create(0, 1, 0), dir)))
		head = vec3_create(0, 0, -1);
	else
		head = vec3_create(0, 1, 0);
	return (vec3_unit(vec3_sub(head, vec3_mul(dir, vec3_dot(dir, head)))));
}
