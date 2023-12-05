/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_command_line_image.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:07:25 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/05 17:55:59 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_command_mode.h"
#include "define.h"
#include <stdlib.h>
#include <mlx.h>

void	reset_command_line_image(t_mlx_ptr *mlx_ptr)
{
	void	*command_line_image;

	command_line_image = mlx_new_image(mlx_ptr->ptr, WDW_WIDTH, WDW_CMD_HEIGHT);
	if (command_line_image == NULL)
		exit(EXIT_FAILURE);
	mlx_put_image_to_window(
		mlx_ptr->ptr,
		mlx_ptr->wdw_ptr,
		command_line_image,
		0,
		WDW_HEIGHT - WDW_CMD_HEIGHT
		);
	mlx_destroy_image(mlx_ptr->ptr, command_line_image);
}
