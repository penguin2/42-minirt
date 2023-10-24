/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_set_viewport.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:11:47 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/23 16:13:17 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "camera.h"
#include <math.h>

void	camera_set_viewport(t_viewport *viewport, t_camera *camera)
{
	const double	len_to_viewport = 1.0;
	const double	len_width = 2.0 * tan(camera->fov / 2) * len_to_viewport;
	const double	len_height = len_width * WDW_HEIGHT / WDW_WIDTH;

	viewport->width = WDW_WIDTH;
	viewport->height = WDW_HEIGHT;
	viewport->dw = vec3_mul(camera->right, len_width / WDW_WIDTH);
	viewport->dh = vec3_mul(camera->up, -1.0 * len_height / WDW_HEIGHT);
	viewport->upper_left
		= vec3_add(
			vec3_add(
				vec3_add(camera->eye, camera->dir),
				vec3_mul(camera->right, -len_width / 2)),
			vec3_mul(camera->up, len_height / 2));
	viewport->upper_left
		= vec3_add(viewport->upper_left, vec3_mul(viewport->dw, 1.0 / 2));
	viewport->upper_left
		= vec3_add(viewport->upper_left, vec3_mul(viewport->dh, 1.0 / 2));
}
