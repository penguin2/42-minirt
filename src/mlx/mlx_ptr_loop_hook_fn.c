/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_ptr_loop_hook_fn.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:34:30 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/17 21:50:29 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_ptr.h"
#include "image.h"
#include <mlx.h>
#include <stdlib.h>

static void	_make_one_image(void *mlx, t_image *image);

int	mlx_ptr_loop_hook_fn(t_mlx_ptr *mlx_ptr)
{
	if (mlx_ptr->is_to_update == false)
		return (0);
	mlx_ptr->is_to_update = false;
	_make_one_image(mlx_ptr->ptr, mlx_ptr->image);
	image_render_scene(mlx_ptr->ptr, mlx_ptr->image, mlx_ptr->scene);
	mlx_put_image_to_window(
		mlx_ptr->ptr, mlx_ptr->wdw_ptr, mlx_ptr->image->ptr, 0, 0);
	mlx_destroy_image(mlx_ptr->ptr, mlx_ptr->image->ptr);
	return (0);
}

static void	_make_one_image(void *mlx, t_image *image)
{
	int	bits_per_pixel;

	image->ptr = mlx_new_image(mlx, image->width, image->height);
	if (image->ptr == NULL)
		exit(EXIT_FAILURE);
	image->addr = mlx_get_data_addr(
			image->ptr, &bits_per_pixel, &image->size_line, &image->endian);
	image->byte_per_pixel = bits_per_pixel / BITS_PER_BYTE;
}
