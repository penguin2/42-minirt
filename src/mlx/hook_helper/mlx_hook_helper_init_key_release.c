/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook_helper_init_key_release.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:22:43 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/07 00:58:08 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_hook_helper.h"
#include <X11/keysym.h>

void	mlx_hook_helper_init_key_release(t_hook *hooks_kr)
{
	mlx_hook_helper_set_hook(hooks_kr++, XK_Shift_L, hook_fn_set_shift_off);
	mlx_hook_helper_set_hook(hooks_kr++, XK_Shift_R, hook_fn_set_shift_off);
}
