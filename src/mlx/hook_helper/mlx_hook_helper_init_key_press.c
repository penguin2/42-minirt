/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook_helper_init_key_press.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:22:43 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/26 22:20:09 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_hook_helper.h"
#include <X11/keysym.h>

static void	_init_key_press_fn(t_mlx_hook_helper *mlx_hook_helper);

void	mlx_hook_helper_init_key_press(t_mlx_hook_helper *mlx_hook_helper)
{
	mlx_hook_helper->key_press[HOOK_KP_ESCAPE] = XK_Escape;
	mlx_hook_helper->key_press[HOOK_KP_LEFT] = XK_Left;
	mlx_hook_helper->key_press[HOOK_KP_RIGHT] = XK_Right;
	mlx_hook_helper->key_press[HOOK_KP_UP] = XK_Up;
	mlx_hook_helper->key_press[HOOK_KP_DOWN] = XK_Down;
	mlx_hook_helper->key_press[HOOK_KP_W] = XK_w;
	mlx_hook_helper->key_press[HOOK_KP_A] = XK_a;
	mlx_hook_helper->key_press[HOOK_KP_S] = XK_s;
	mlx_hook_helper->key_press[HOOK_KP_D] = XK_d;
	mlx_hook_helper->key_press[HOOK_KP_SPACE] = XK_space;
	mlx_hook_helper->key_press[HOOK_KP_SHIFT_L] = XK_Shift_L;
	mlx_hook_helper->key_press[HOOK_KP_SHIFT_R] = XK_Shift_R;
	_init_key_press_fn(mlx_hook_helper);
}

static void	_init_key_press_fn(t_mlx_hook_helper *mlx_hook_helper)
{
	mlx_hook_helper->key_press_fn[HOOK_KP_ESCAPE] = hook_fn_exit;
	mlx_hook_helper->key_press_fn[HOOK_KP_LEFT] = hook_fn_rotate_camera;
	mlx_hook_helper->key_press_fn[HOOK_KP_RIGHT] = hook_fn_rotate_camera;
	mlx_hook_helper->key_press_fn[HOOK_KP_UP] = hook_fn_rotate_camera;
	mlx_hook_helper->key_press_fn[HOOK_KP_DOWN] = hook_fn_rotate_camera;
	mlx_hook_helper->key_press_fn[HOOK_KP_W] = hook_fn_move_camera;
	mlx_hook_helper->key_press_fn[HOOK_KP_A] = hook_fn_move_camera;
	mlx_hook_helper->key_press_fn[HOOK_KP_S] = hook_fn_move_camera;
	mlx_hook_helper->key_press_fn[HOOK_KP_D] = hook_fn_move_camera;
	mlx_hook_helper->key_press_fn[HOOK_KP_SPACE] = hook_fn_move_camera;
	mlx_hook_helper->key_press_fn[HOOK_KP_SHIFT_L] = hook_fn_set_shift_on;
	mlx_hook_helper->key_press_fn[HOOK_KP_SHIFT_R] = hook_fn_set_shift_on;
}
