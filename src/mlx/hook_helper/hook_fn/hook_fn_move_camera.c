/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_fn_move_camera.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:54:21 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/26 22:10:59 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "define.h"
#include "mlx_hook_helper.h"
#include "mlx_ptr.h"

void	hook_fn_move_camera(t_mlx_ptr *mlx_ptr, int keycode)
{
	int					*key_press;
	t_camera			*camera;
	t_camera_direction	camera_direction;

	key_press = mlx_ptr->mlx_hook_helper.key_press;
	camera = &mlx_ptr->scene->camera;
	if (keycode == key_press[HOOK_KP_W])
		camera_direction = CAMERA_DIRECTION_FRONT;
	else if (keycode == key_press[HOOK_KP_A])
		camera_direction = CAMERA_DIRECTION_LEFT;
	else if (keycode == key_press[HOOK_KP_S])
		camera_direction = CAMERA_DIRECTION_BACK;
	else if (keycode == key_press[HOOK_KP_D])
		camera_direction = CAMERA_DIRECTION_RIGHT;
	else if (keycode == key_press[HOOK_KP_SPACE] && !mlx_ptr->is_shift_pressed)
		camera_direction = CAMERA_DIRECTION_UP;
	else if (keycode == key_press[HOOK_KP_SPACE] && mlx_ptr->is_shift_pressed)
		camera_direction = CAMERA_DIRECTION_DOWN;
	else
		return ;
	if (camera_move(camera, camera_direction) == SUCCESS)
		mlx_ptr->is_to_update = true;
}
