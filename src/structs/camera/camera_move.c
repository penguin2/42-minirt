/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:51:37 by taekklee          #+#    #+#             */
/*   Updated: 2023/12/15 20:44:30 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "define.h"
#include "libvec3.h"

int	camera_move(t_camera *camera, t_camera_direction camera_direction)
{
	t_vec3	move;
	t_vec3	new_eye;

	if (camera_direction == CAMERA_DIRECTION_FRONT)
		move = camera->dir;
	else if (camera_direction == CAMERA_DIRECTION_LEFT)
		move = vec3_mul(camera->right, -1.0);
	else if (camera_direction == CAMERA_DIRECTION_BACK)
		move = vec3_mul(camera->dir, -1.0);
	else if (camera_direction == CAMERA_DIRECTION_RIGHT)
		move = camera->right;
	else if (camera_direction == CAMERA_DIRECTION_UP)
		move = camera->up;
	else if (camera_direction == CAMERA_DIRECTION_DOWN)
		move = vec3_mul(camera->up, -1.0);
	else
		return (ERROR);
	new_eye = vec3_add(camera->eye, vec3_mul(move, UNIT_LEN_CAMERA_MOVE));
	if (camera_check_eye(new_eye) == ERROR)
		return (ERROR);
	camera->eye = new_eye;
	camera_set_viewport(camera, &camera->viewport);
	return (SUCCESS);
}
