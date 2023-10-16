/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_ptr_loop_hook_fn.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:34:30 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/16 20:40:07 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_ptr.h"
#include "image.h"
#include <mlx.h>

int	mlx_ptr_loop_hook_fn(t_mlx_ptr *mlx_ptr)
{
	if (mlx_ptr->is_to_update == false)
		return (0);
	mlx_ptr->is_to_update = false;
	mlx_ptr->image->ptr = mlx_new_image(
			mlx_ptr->ptr, mlx_ptr->image->width, mlx_ptr->image->height);
	image_render_scene(mlx_ptr->image, mlx_ptr->scene);
	mlx_put_image_to_window(
		mlx_ptr->ptr, mlx_ptr->wdw_ptr, mlx_ptr->image->ptr, 0, 0);
	mlx_destroy_image(mlx_ptr->ptr, mlx_ptr->image->ptr);
	mlx_ptr->image->ptr = NULL;
	return (0);
}
