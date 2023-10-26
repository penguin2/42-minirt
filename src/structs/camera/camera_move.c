/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:51:37 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/26 17:00:48 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "libvec3.h"

void	camera_move(t_camera *camera, t_camera_direction camera_direction)
{
	t_vec3	move;

	if (camera_direction == CAMERA_DIRECTION_FRONT)
		move = camera->dir;
	else if (camera_direction == CAMERA_DIRECTION_LEFT)
		move = vec3_mul(camera->right, -1.0);
	else if (camera_direction == CAMERA_DIRECTION_BACK)
		move = vec3_mul(camera->dir, -1.0);
	else if (camera_direction == CAMERA_DIRECTION_RIGHT)
		move = camera->right;
	else
		return ;
	camera->eye = vec3_add(camera->eye, vec3_mul(move, 0.5));
	camera_set_viewport(camera, &camera->viewport);
}
