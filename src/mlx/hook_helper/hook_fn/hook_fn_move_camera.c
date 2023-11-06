/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_fn_move_camera.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:54:21 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/07 01:24:15 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "define.h"
#include "mlx_hook_helper.h"
#include "mlx_ptr.h"
#include <X11/keysym.h>

void	hook_fn_move_camera(t_mlx_ptr *mlx_ptr, int keycode)
{
	t_camera			*camera;
	t_camera_direction	camera_direction;

	camera = &mlx_ptr->scene->camera;
	if (keycode == XK_w)
		camera_direction = CAMERA_DIRECTION_FRONT;
	else if (keycode == XK_a)
		camera_direction = CAMERA_DIRECTION_LEFT;
	else if (keycode == XK_s)
		camera_direction = CAMERA_DIRECTION_BACK;
	else if (keycode == XK_d)
		camera_direction = CAMERA_DIRECTION_RIGHT;
	else if (keycode == XK_space && !mlx_ptr->is_shift_pressed)
		camera_direction = CAMERA_DIRECTION_UP;
	else if (keycode == XK_space && mlx_ptr->is_shift_pressed)
		camera_direction = CAMERA_DIRECTION_DOWN;
	else
		return ;
	if (camera_move(camera, camera_direction) == SUCCESS)
		mlx_ptr->is_to_update = true;
}
