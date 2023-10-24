/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook_helper_init_button_release.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:31:35 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/23 17:32:24 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_hook_helper.h"

static void	_init_button_release_fn(t_mlx_hook_helper *mlx_hook_helper);

void	mlx_hook_helper_init_button_release(t_mlx_hook_helper *mlx_hook_helper)
{
	mlx_hook_helper->button_release[HOOK_BR_BUTTON_LEFT] = BUTTON_LEFT_X;
	_init_button_release_fn(mlx_hook_helper);
}

static void	_init_button_release_fn(t_mlx_hook_helper *mlx_hook_helper)
{
	mlx_hook_helper->button_release_fn[HOOK_BR_BUTTON_LEFT]
		= hook_fn_set_button_left_off;
}
