/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:18:06 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/18 20:48:09 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "image.h"

static int	_is_big_endian(void);

int	image_init(t_image *image, t_camera *camera)
{
	image->scene = NULL;
	image->width = camera->viewport.width;
	image->height = camera->viewport.height;
	image->local_endian = _is_big_endian();
	return (SUCCESS);
}

static int	_is_big_endian(void)
{
	unsigned int	x;

	x = 0xff;
	if (*(unsigned char *)&x == 0xff)
		return (0);
	return (1);
}
