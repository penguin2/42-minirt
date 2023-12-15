/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_ptr_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:37:54 by taekklee          #+#    #+#             */
/*   Updated: 2023/12/11 19:13:35 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "mlx_ptr.h"
#include <mlx.h>
#include <stddef.h>

static int	_set_mlx_init(t_mlx_ptr *mlx_ptr);

int	mlx_ptr_init(t_mlx_ptr *mlx_ptr, t_image *image, t_scene *scene)
{
	if (_set_mlx_init(mlx_ptr) == ERROR
		|| mlx_hook_helper_init(&mlx_ptr->mlx_hook_helper) == ERROR)
		return (ERROR);
	mlx_ptr->scene = scene;
	mlx_ptr->image = image;
	mlx_ptr->is_to_update = true;
	mlx_ptr->is_button_left_pressed = false;
	mlx_ptr->is_shift_pressed = false;
	mlx_ptr->mode = MLX_MODE_NORMAL;
	mlx_ptr->selected_object = NULL;
	return (SUCCESS);
}

static int	_set_mlx_init(t_mlx_ptr *mlx_ptr)
{
	mlx_ptr->ptr = mlx_init();
	if (mlx_ptr->ptr == NULL)
		return (ERROR);
	mlx_ptr->wdw_ptr = mlx_new_window(
			mlx_ptr->ptr, WDW_WIDTH, WDW_HEIGHT, NAME);
	if (mlx_ptr->wdw_ptr == NULL)
		return (ERROR);
	return (SUCCESS);
}
