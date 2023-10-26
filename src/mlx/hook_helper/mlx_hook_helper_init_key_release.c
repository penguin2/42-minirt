/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook_helper_init_key_release.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:22:43 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/26 22:23:40 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_hook_helper.h"
#include <X11/keysym.h>

static void	_init_key_release_fn(t_mlx_hook_helper *mlx_hook_helper);

void	mlx_hook_helper_init_key_release(t_mlx_hook_helper *mlx_hook_helper)
{
	mlx_hook_helper->key_release[HOOK_KR_SHIFT_L] = XK_Shift_L;
	mlx_hook_helper->key_release[HOOK_KR_SHIFT_R] = XK_Shift_R;
	_init_key_release_fn(mlx_hook_helper);
}

static void	_init_key_release_fn(t_mlx_hook_helper *mlx_hook_helper)
{
	mlx_hook_helper->key_release_fn[HOOK_KR_SHIFT_L] = hook_fn_set_shift_off;
	mlx_hook_helper->key_release_fn[HOOK_KR_SHIFT_R] = hook_fn_set_shift_off;
}
