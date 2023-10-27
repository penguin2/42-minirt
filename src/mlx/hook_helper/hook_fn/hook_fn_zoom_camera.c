/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_fn_zoom_camera.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 02:11:42 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/27 02:51:43 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_ptr.h"
#include "define.h"

void	hook_fn_zoom_camera(t_mlx_ptr *mlx_ptr, int keycode)
{
	double	unit_fov;

	if (mlx_ptr->is_shift_pressed)
		unit_fov = UNIT_FOV_CAMERA_ZOOM;
	else
		unit_fov = -UNIT_FOV_CAMERA_ZOOM;
	if (camera_zoom(&mlx_ptr->scene->camera, unit_fov) == SUCCESS)
		mlx_ptr->is_to_update = true;
	(void)keycode;
}
