/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook_helper_init_key_press.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:22:43 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/23 14:28:19 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_hook_helper.h"
#include <X11/keysym.h>

static void	_init_key_press_fn(t_mlx_hook_helper *mlx_hook_helper);

void	mlx_hook_helper_init_key_press(t_mlx_hook_helper *mlx_hook_helper)
{
	mlx_hook_helper->key_press[HOOK_KP_ESCAPE] = XK_Escape;
	_init_key_press_fn(mlx_hook_helper);
}

static void	_init_key_press_fn(t_mlx_hook_helper *mlx_hook_helper)
{
	mlx_hook_helper->key_press_fn[HOOK_KP_ESCAPE] = hook_fn_exit;
}
