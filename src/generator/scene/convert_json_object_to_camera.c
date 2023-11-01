/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_json_object_to_camera.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 21:27:09 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/01 14:50:17 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generator.h"
#include "define.h"
#include "libft.h"
#include "parse.h"
#include "math.h"
#include "utils.h"
#include "libvec3.h"

// 一時的にcamera_initから持ってきています
static void	_set_viewport(t_viewport *viewport, t_camera *camera)
{
	const double	len_to_viewport = 1.0;
	const double	len_width = 2.0 * tan(camera->fov / 2) * len_to_viewport;
	const double	len_height = len_width * WDW_HEIGHT / WDW_WIDTH;

	viewport->width = WDW_WIDTH;
	viewport->height = WDW_HEIGHT;
	viewport->dw = vec3_mul(camera->right, len_width / WDW_WIDTH);
	viewport->dh = vec3_mul(camera->up, -1.0 * len_height / WDW_HEIGHT);
	viewport->upper_left
		= vec3_add(
			vec3_add(
				vec3_add(camera->eye, camera->dir),
				vec3_mul(camera->right, -len_width / 2)),
			vec3_mul(camera->up, len_height / 2));
	viewport->upper_left
		= vec3_add(viewport->upper_left, vec3_mul(viewport->dw, 1.0 / 2));
	viewport->upper_left
		= vec3_add(viewport->upper_left, vec3_mul(viewport->dh, 1.0 / 2));
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

static void	_set_camera_info(t_camera *camera, double fov)
{
	camera->dir = vec3_unit(camera->dir);
	camera->fov = fov * (2.0 * PI / 360);
	camera->up = _get_camera_up_vector(camera->dir);
	camera->right = vec3_cross(camera->dir, camera->up);
	_set_viewport(&camera->viewport, camera);
}

int	convert_json_object_to_camera(const t_json_node *node, t_camera *camera)
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
	_set_camera_info(camera, fov);
	return (SUCCESS);
}
