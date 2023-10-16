/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:18:06 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/16 20:35:12 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "image.h"

int	image_init(t_image *image, t_camera *camera)
{
	image->ptr = NULL;
	image->height = camera->viewport.height;
	image->width = camera->viewport.width;
	return (SUCCESS);
}
