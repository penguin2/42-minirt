/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_zoom.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 02:26:51 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/27 02:59:30 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "define.h"

int	camera_zoom(t_camera *camera, double deg)
{
	const double	new_fov = camera->fov + deg * DEG_TO_RAD;

	if (new_fov < FOV_LOWER_LIMIT * DEG_TO_RAD
		|| new_fov > FOV_UPPER_LIMIT * DEG_TO_RAD)
		return (ERROR);
	camera->fov = new_fov;
	camera_set_viewport(camera, &camera->viewport);
	return (SUCCESS);
}
