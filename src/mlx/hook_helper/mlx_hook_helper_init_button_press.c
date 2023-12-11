/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook_helper_init_button_press.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:01:14 by taekklee          #+#    #+#             */
/*   Updated: 2023/12/13 14:02:00 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_hook_helper.h"

void	mlx_hook_helper_init_button_press(t_hook *hooks_bp)
{
	mlx_hook_helper_set_hook(
		hooks_bp++, BUTTON_RIGHT_X, hook_fn_handle_material);
	mlx_hook_helper_set_hook(
		hooks_bp++, BUTTON_LEFT_X, hook_fn_select_object);
}
