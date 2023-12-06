/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_string_put_cmd_mode.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:13:30 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/06 15:13:18 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_command_mode.h"
#include "define.h"
#include <mlx.h>

int	mlx_string_put_cmd_mode(t_mlx_ptr *mlx_ptr, char *str, int color)
{
	mlx_string_put(
		mlx_ptr->ptr,
		mlx_ptr->wdw_ptr,
		WDW_WIDTH / 100.0,
		WDW_HEIGHT - (WDW_HEIGHT / 60.0),
		color,
		str
		);
	return (SUCCESS);
}
