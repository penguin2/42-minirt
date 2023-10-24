/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook_helper_init_key_press.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:22:43 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/24 17:44:52 by taekklee         ###   ########.fr       */
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
	_init_key_press_fn(mlx_hook_helper);
}

static void	_init_key_press_fn(t_mlx_hook_helper *mlx_hook_helper)
{
	mlx_hook_helper->key_press_fn[HOOK_KP_ESCAPE] = hook_fn_exit;
	mlx_hook_helper->key_press_fn[HOOK_KP_LEFT] = hook_fn_rotate_camera;
	mlx_hook_helper->key_press_fn[HOOK_KP_RIGHT] = hook_fn_rotate_camera;
	mlx_hook_helper->key_press_fn[HOOK_KP_UP] = hook_fn_rotate_camera;
	mlx_hook_helper->key_press_fn[HOOK_KP_DOWN] = hook_fn_rotate_camera;
}
