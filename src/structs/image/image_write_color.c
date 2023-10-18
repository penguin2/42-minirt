/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_write_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 21:59:58 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/18 00:45:27 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image.h"
#include <mlx.h>

void	image_write_color(
			void *mlx, t_image *image, unsigned char *dst, int color)
{
	const unsigned int	mlx_color = mlx_get_color_value(mlx, color);
	size_t				sz;
	size_t				i;

	if (image->local_endian == image->endian)
		*(unsigned int *)dst = mlx_color;
	else
	{
		i = 0;
		sz = image->byte_per_pixel;
		while (i < sz)
		{
			dst[i] = ((unsigned char *)&mlx_color)[sz - 1 - i];
			++i;
		}
	}
}
