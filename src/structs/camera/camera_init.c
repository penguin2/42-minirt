/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:08:04 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/20 16:31:29 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "define.h"
#include "utils.h"
#include <math.h>
#include <stdbool.h>

static void		_set_viewport(t_viewport *viewport, t_camera *camera);
static t_vec3	_get_camera_up_vector(t_vec3 dir);

int	camera_init(t_camera *camera)
{
	camera->eye = vec3_create(0, 20, -10);
	camera->dir = vec3_unit(vec3_create(0.0, -1.0, 0.0));
	camera->up = _get_camera_up_vector(camera->dir);
	camera->right = vec3_cross(camera->dir, camera->up);
	camera->fov = 70 * (2.0 * PI / 360);
	_set_viewport(&camera->viewport, camera);
	return (SUCCESS);
}

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
