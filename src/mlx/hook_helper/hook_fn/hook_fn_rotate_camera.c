/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_fn_rotate_camera.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:17:53 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/26 20:49:01 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "define.h"
#include "mlx_hook_helper.h"
#include "mlx_ptr.h"

void	hook_fn_rotate_camera(void *_mlx_ptr, int keycode)
{
	t_mlx_ptr			*mlx_ptr;
	int					*key_press;
	t_camera			*camera;
	t_camera_rotation	camera_rotation;

	mlx_ptr = _mlx_ptr;
	key_press = mlx_ptr->mlx_hook_helper.key_press;
	camera = &mlx_ptr->scene->camera;
	if (keycode == key_press[HOOK_KP_UP])
		camera_rotation = CAMERA_ROTATION_UP;
	else if (keycode == key_press[HOOK_KP_LEFT])
		camera_rotation = CAMERA_ROTATION_LEFT;
	else if (keycode == key_press[HOOK_KP_DOWN])
		camera_rotation = CAMERA_ROTATION_DOWN;
	else if (keycode == key_press[HOOK_KP_RIGHT])
		camera_rotation = CAMERA_ROTATION_RIGHT;
	else
		return ;
	if (camera_rotate(camera, camera_rotation) == SUCCESS)
		mlx_ptr->is_to_update = true;
}
