/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_fn_enter_cmd_mode.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:52:14 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/09 13:40:53 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_command_mode.h"
#include "define.h"

void	hook_fn_enter_cmd_mode(t_mlx_ptr *mlx_ptr, int keycode)
{
	(void)keycode;
	mlx_ptr->mode = MLX_MODE_COMMAND;
	reset_image(mlx_ptr, WDW_CMD_HEIGHT);
	mlx_buffer_flush(mlx_ptr->buffer);
	mlx_buffer_write(mlx_ptr->buffer, ':');
	mlx_putcmd(mlx_ptr, mlx_ptr->buffer, COLOR_YELLOW, SUCCESS);
}
