/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_putcmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:13:30 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/09 13:59:58 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_command_mode.h"
#include "define.h"
#include <mlx.h>

int	mlx_putcmd(t_mlx_ptr *mlx_ptr, char *str, int color, int return_val)
{
	const int	width = WDW_WIDTH / 100;
	const int	height = WDW_HEIGHT - (WDW_HEIGHT / 90);

	mlx_ptr->is_to_update = false;
	reset_image(mlx_ptr, WDW_CMD_HEIGHT);
	mlx_string_put(mlx_ptr->ptr, mlx_ptr->wdw_ptr, width, height, color, str);
	return (return_val);
}
