/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_fn_input_digit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:47:52 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/06 15:14:01 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "mlx_command_mode.h"
#include <X11/keysym.h>

void	hook_fn_input_digit(t_mlx_ptr *mlx_ptr, int keycode)
{
	if (mlx_ptr->is_shift_pressed)
		return ;
	if (keycode == XK_1)
		mlx_buffer_write(mlx_ptr->buffer, '1');
	else if (keycode == XK_2)
		mlx_buffer_write(mlx_ptr->buffer, '2');
	else if (keycode == XK_3)
		mlx_buffer_write(mlx_ptr->buffer, '3');
	else if (keycode == XK_4)
		mlx_buffer_write(mlx_ptr->buffer, '4');
	else if (keycode == XK_5)
		mlx_buffer_write(mlx_ptr->buffer, '5');
	else if (keycode == XK_6)
		mlx_buffer_write(mlx_ptr->buffer, '6');
	else if (keycode == XK_7)
		mlx_buffer_write(mlx_ptr->buffer, '7');
	else if (keycode == XK_8)
		mlx_buffer_write(mlx_ptr->buffer, '8');
	else if (keycode == XK_9)
		mlx_buffer_write(mlx_ptr->buffer, '9');
	else if (keycode == XK_0)
		mlx_buffer_write(mlx_ptr->buffer, '0');
	mlx_string_put_cmd_mode(mlx_ptr, mlx_ptr->buffer, MLX_COMMAND_LINE_COLOR);
}
