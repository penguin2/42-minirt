/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:08:04 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/20 21:42:17 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "define.h"
#include "utils.h"
#include "parse.h"
#include "message_parse.h"
#include <stdbool.h>
#include <float.h>

static t_vec3	_get_camera_up_vector(t_vec3 dir);
static void		_set_camera_infomation(t_camera *camera, double fov);

int	camera_init(const t_json_node *node, t_camera *camera)
{
	const t_vla			*camera_list = get_list(node, ID_CAMERA, 1);
	const t_json_node	*camera_dict = camera_list->array[0];
	double				fov;

	if (camera_dict->type != NODE_DICT)
		return (ERROR);
	if (query_set_double(
			query_create(camera_dict, FOV, &fov, true),
			range_create(0.0, 180.0)) == ERROR
		|| list_to_vec3(get_list(camera_dict, COORDINATES, 3),
			&camera->eye, -DBL_MAX, DBL_MAX) == ERROR
		|| list_to_vec3(get_list(camera_dict, DIRECTION, 3),
			&camera->dir, -1.0, 1.0) == ERROR
		|| try_vec3_unit(&camera->dir) == ERROR)
		return (ERROR);
	_set_camera_infomation(camera, fov);
	return (SUCCESS);
}

static void	_set_camera_infomation(t_camera *camera, double fov)
{
	if (fov < FOV_LOWER_LIMIT)
	{
		fov = FOV_LOWER_LIMIT;
		print_warning(WARNING_FOV_IS_0);
	}
	else if (FOV_UPPER_LIMIT < fov)
	{
		fov = FOV_UPPER_LIMIT;
		print_warning(WARNING_FOV_IS_180);
	}
	camera->fov = fov * (2.0 * PI / 360);
	camera->dir = camera->dir;
	camera->up = _get_camera_up_vector(camera->dir);
	camera->right = vec3_cross(camera->dir, camera->up);
	camera_set_viewport(camera, &camera->viewport);
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
