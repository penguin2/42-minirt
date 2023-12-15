/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_command_line_image.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:07:25 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/09 13:14:09 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_command_mode.h"
#include "define.h"
#include <stdlib.h>
#include <mlx.h>

void	reset_image(t_mlx_ptr *mlx_ptr, int image_height)
{
	void		*image;
	const int	height = WDW_HEIGHT - image_height;

	image = mlx_new_image(mlx_ptr->ptr, WDW_WIDTH, image_height);
	if (image == NULL)
		exit(EXIT_FAILURE);
	mlx_put_image_to_window(mlx_ptr->ptr, mlx_ptr->wdw_ptr, image, 0, height);
	mlx_destroy_image(mlx_ptr->ptr, image);
}
