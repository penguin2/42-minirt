/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_fn_delete.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:05:06 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/09 13:37:25 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_command_mode.h"
#include "define.h"
#include <X11/keysym.h>

void	hook_fn_delete(t_mlx_ptr *mlx_ptr, int keycode)
{
	(void)keycode;
	if (mlx_buffer_remove(mlx_ptr->buffer) == 0)
		exit_cmd_mode(mlx_ptr);
	else
	{
		reset_image(mlx_ptr, WDW_CMD_HEIGHT);
		mlx_putcmd(mlx_ptr, mlx_ptr->buffer, COLOR_YELLOW, SUCCESS);
	}
}
