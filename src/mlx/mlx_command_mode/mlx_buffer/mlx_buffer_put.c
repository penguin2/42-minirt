/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_buffer_put.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:13:30 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/05 17:50:03 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_command_mode.h"
#include "define.h"
#include <mlx.h>

int	mlx_buffer_put(t_mlx_ptr *mlx_ptr)
{
	mlx_string_put(
		mlx_ptr->ptr,
		mlx_ptr->wdw_ptr,
		WDW_CMD_WIDTH_START,
		WDW_HEIGHT - (WDW_CMD_HEIGHT / 3),
		MLX_COMMAND_LINE_COLOR,
		mlx_ptr->buffer
		);
	return (SUCCESS);
}
