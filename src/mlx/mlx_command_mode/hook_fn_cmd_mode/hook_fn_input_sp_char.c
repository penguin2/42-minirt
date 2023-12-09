/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_fn_input_sp_char.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:23:48 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/09 16:35:53 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_hook_helper.h"
#include "mlx_command_mode.h"
#include "define.h"
#include <X11/keysym.h>

void	hook_fn_input_sp_char(t_mlx_ptr *mlx_ptr, int keycode)
{
	if (keycode == XK_space)
		mlx_buffer_write(mlx_ptr->buffer, ' ');
	else if (keycode == XK_comma && !mlx_ptr->is_shift_pressed)
		mlx_buffer_write(mlx_ptr->buffer, ',');
	else if (keycode == XK_period && !mlx_ptr->is_shift_pressed)
		mlx_buffer_write(mlx_ptr->buffer, '.');
	else if (keycode == XK_minus && !mlx_ptr->is_shift_pressed)
		mlx_buffer_write(mlx_ptr->buffer, '-');
	else if (keycode == XK_slash && !mlx_ptr->is_shift_pressed)
		mlx_buffer_write(mlx_ptr->buffer, '/');
	else if ((keycode == XK_underscore && !mlx_ptr->is_shift_pressed)
		|| (keycode == XK_minus && mlx_ptr->is_shift_pressed))
		mlx_buffer_write(mlx_ptr->buffer, '_');
	else
		return ;
	mlx_putcmd(mlx_ptr, mlx_ptr->buffer, COLOR_YELLOW, SUCCESS);
}
