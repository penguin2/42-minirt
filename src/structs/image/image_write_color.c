/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_write_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 21:59:58 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/17 22:03:38 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image.h"

void	image_write_color(
			t_image *image, unsigned char *dst, unsigned int color)
{
	size_t	sz;
	size_t	i;

	if (image->local_endian == image->endian)
		*(unsigned int *)dst = color;
	else
	{
		i = 0;
		sz = image->byte_per_pixel;
		while (i < sz)
		{
			dst[i] = ((unsigned char *)&color)[sz - 1 - i];
			++i;
		}
	}
}
