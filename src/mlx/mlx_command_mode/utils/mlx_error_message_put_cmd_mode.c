/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_error_message_put_cmd_mode.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:51:54 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/06 19:32:07 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_command_mode.h"
#include "define.h"

int	mlx_error_message_put_cmd_mode(t_mlx_ptr *mlx_ptr, char *str)
{
	mlx_ptr->is_to_update = false;
	reset_command_line_image(mlx_ptr);
	mlx_string_put_cmd_mode(
		mlx_ptr,
		str,
		MLX_COMMAND_LINE_ERROR_COLOR
		);
	return (ERROR);
}
