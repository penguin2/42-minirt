/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:51:09 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/27 10:21:18 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "define.h"
#include "libvec3.h"
#include "utils.h"

int	camera_rotate(t_camera *camera, t_camera_rotation camera_rotation)
{
	const double	theta = 2 * PI / COUNT_TO_ROTATE_CAMERA_ONCE;

	if (camera_rotation == CAMERA_ROTATION_UP)
		rotate_two_vecs_clockwise(&camera->dir, &camera->up, theta);
	else if (camera_rotation == CAMERA_ROTATION_LEFT)
		rotate_two_vecs_clockwise(&camera->right, &camera->dir, theta);
	else if (camera_rotation == CAMERA_ROTATION_DOWN)
		rotate_two_vecs_clockwise(&camera->dir, &camera->up, -theta);
	else if (camera_rotation == CAMERA_ROTATION_RIGHT)
		rotate_two_vecs_clockwise(&camera->right, &camera->dir, -theta);
	else if (camera_rotation == CAMERA_ROTATION_ROLL_LEFT)
		rotate_two_vecs_clockwise(&camera->right, &camera->up, theta);
	else if (camera_rotation == CAMERA_ROTATION_ROLL_RIGHT)
		rotate_two_vecs_clockwise(&camera->right, &camera->up, -theta);
	else
		return (ERROR);
	camera_set_viewport(camera, &camera->viewport);
	return (SUCCESS);
}
