/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook_helper_init_button_press.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:01:14 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/23 17:31:20 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_hook_helper.h"

static void	_init_button_press_fn(t_mlx_hook_helper *mlx_hook_helper);

void	mlx_hook_helper_init_button_press(t_mlx_hook_helper *mlx_hook_helper)
{
	mlx_hook_helper->button_press[HOOK_BP_BUTTON_LEFT] = BUTTON_LEFT_X;
	_init_button_press_fn(mlx_hook_helper);
}

static void	_init_button_press_fn(t_mlx_hook_helper *mlx_hook_helper)
{
	mlx_hook_helper->button_press_fn[HOOK_BP_BUTTON_LEFT]
		= hook_fn_set_button_left_on;
}
