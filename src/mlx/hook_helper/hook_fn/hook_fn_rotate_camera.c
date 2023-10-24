/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_fn_rotate_camera.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:17:53 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/24 18:03:55 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "define.h"
#include "mlx_hook_helper.h"
#include "mlx_ptr.h"

void	hook_fn_rotate_camera(void *mlx_ptr, int keycode)
{
	const int	*key_press = ((t_mlx_ptr *)mlx_ptr)->mlx_hook_helper.key_press;
	double		theta;
	void		(*rotate_camera_fp)(t_camera *camera, double theta);

	theta = 2 * PI / COUNT_TO_ROTATE_ONCE;
	if (keycode == key_press[HOOK_KP_RIGHT]
		|| keycode == key_press[HOOK_KP_DOWN])
		theta = -theta;
	if (keycode == key_press[HOOK_KP_LEFT]
		|| keycode == key_press[HOOK_KP_RIGHT])
		rotate_camera_fp = camera_horizontal_rotate;
	else
		rotate_camera_fp = camera_vertical_rotate;
	rotate_camera_fp(&((t_mlx_ptr *)mlx_ptr)->scene->camera, theta);
	((t_mlx_ptr *)mlx_ptr)->is_to_update = true;
}
