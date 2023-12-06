/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_fn_delete.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:05:06 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/06 15:15:09 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_command_mode.h"
#include <X11/keysym.h>

void	hook_fn_delete(t_mlx_ptr *mlx_ptr, int keycode)
{
	(void)keycode;
	if (mlx_buffer_remove(mlx_ptr->buffer) == 0)
		exit_cmd_mode(mlx_ptr);
	else
	{
		reset_command_line_image(mlx_ptr);
		mlx_string_put_cmd_mode(
			mlx_ptr,
			mlx_ptr->buffer,
			MLX_COMMAND_LINE_COLOR
			);
	}
}
