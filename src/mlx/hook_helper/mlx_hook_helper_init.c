/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook_helper_init.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:18:40 by taekklee          #+#    #+#             */
/*   Updated: 2023/12/15 20:01:03 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "mlx_hook_helper.h"
#include "mlx_command_mode.h"

int	mlx_hook_helper_init(t_mlx_hook_helper *mlx_hook_helper)
{
	mlx_hook_helper_init_key_press(mlx_hook_helper->hooks_key_press);
	mlx_hook_helper_init_key_release(mlx_hook_helper->hooks_key_release);
	mlx_hook_helper_init_button_press(mlx_hook_helper->hooks_button_press);
	mlx_hook_helper_init_key_press_cmd_mode(
		mlx_hook_helper->hooks_key_press_cmd_mode);
	return (SUCCESS);
}
