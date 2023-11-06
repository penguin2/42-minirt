/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_fn_rotate_camera.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:17:53 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/07 01:25:45 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "define.h"
#include "mlx_hook_helper.h"
#include "mlx_ptr.h"
#include <X11/keysym.h>

void	hook_fn_rotate_camera(t_mlx_ptr *mlx_ptr, int keycode)
{
	t_camera			*camera;
	t_camera_rotation	camera_rotation;

	camera = &mlx_ptr->scene->camera;
	if (keycode == XK_Up)
		camera_rotation = CAMERA_ROTATION_UP;
	else if (keycode == XK_Left)
		camera_rotation = CAMERA_ROTATION_LEFT;
	else if (keycode == XK_Down)
		camera_rotation = CAMERA_ROTATION_DOWN;
	else if (keycode == XK_Right)
		camera_rotation = CAMERA_ROTATION_RIGHT;
	else if (keycode == XK_q)
		camera_rotation = CAMERA_ROTATION_ROLL_LEFT;
	else if (keycode == XK_e)
		camera_rotation = CAMERA_ROTATION_ROLL_RIGHT;
	else
		return ;
	if (camera_rotate(camera, camera_rotation) == SUCCESS)
		mlx_ptr->is_to_update = true;
}
