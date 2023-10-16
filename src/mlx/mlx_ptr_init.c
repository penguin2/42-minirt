/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_ptr_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:37:54 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/16 20:40:17 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "mlx_ptr.h"
#include <mlx.h>
#include <stddef.h>

int	mlx_ptr_init(t_mlx_ptr *mlx_ptr, t_image *image, t_scene *scene)
{
	mlx_ptr->ptr = mlx_init();
	if (mlx_ptr->ptr == NULL)
		return (ERROR);
	mlx_ptr->wdw_ptr = mlx_new_window(
			mlx_ptr->ptr, WDW_WIDTH, WDW_HEIGHT, NAME);
	mlx_ptr->scene = scene;
	mlx_ptr->image = image;
	mlx_ptr->is_to_update = true;
	return (SUCCESS);
}
