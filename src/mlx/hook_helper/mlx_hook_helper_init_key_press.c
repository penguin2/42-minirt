/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook_helper_init_key_press.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:22:43 by taekklee          #+#    #+#             */
/*   Updated: 2023/12/05 15:51:51 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_hook_helper.h"
#include <X11/keysym.h>

void	mlx_hook_helper_init_key_press(t_hook *hooks_kp)
{
	mlx_hook_helper_set_hook(hooks_kp++, XK_Escape, hook_fn_exit);
	mlx_hook_helper_set_hook(hooks_kp++, XK_Left, hook_fn_rotate_camera);
	mlx_hook_helper_set_hook(hooks_kp++, XK_Right, hook_fn_rotate_camera);
	mlx_hook_helper_set_hook(hooks_kp++, XK_Up, hook_fn_rotate_camera);
	mlx_hook_helper_set_hook(hooks_kp++, XK_Down, hook_fn_rotate_camera);
	mlx_hook_helper_set_hook(hooks_kp++, XK_q, hook_fn_rotate_camera);
	mlx_hook_helper_set_hook(hooks_kp++, XK_e, hook_fn_rotate_camera);
	mlx_hook_helper_set_hook(hooks_kp++, XK_w, hook_fn_move_camera);
	mlx_hook_helper_set_hook(hooks_kp++, XK_a, hook_fn_move_camera);
	mlx_hook_helper_set_hook(hooks_kp++, XK_s, hook_fn_move_camera);
	mlx_hook_helper_set_hook(hooks_kp++, XK_d, hook_fn_move_camera);
	mlx_hook_helper_set_hook(hooks_kp++, XK_space, hook_fn_move_camera);
	mlx_hook_helper_set_hook(hooks_kp++, XK_Shift_L, hook_fn_set_shift_on);
	mlx_hook_helper_set_hook(hooks_kp++, XK_Shift_R, hook_fn_set_shift_on);
	mlx_hook_helper_set_hook(hooks_kp++, XK_z, hook_fn_zoom_camera);
	mlx_hook_helper_set_hook(hooks_kp++, XK_F1, hook_fn_save_scene);
	mlx_hook_helper_set_hook(hooks_kp++, XK_colon, hook_fn_enter_cmd_mode);
	mlx_hook_helper_set_hook(hooks_kp++, XK_semicolon, hook_fn_enter_cmd_mode);
}
