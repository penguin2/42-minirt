/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_zoom.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 02:26:51 by taekklee          #+#    #+#             */
/*   Updated: 2023/12/18 16:15:57 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "define.h"
#include "utils.h"

int	camera_zoom(t_camera *camera, double deg)
{
	const double	new_fov = camera->fov + deg * DEG_TO_RAD;

	if (is_lower(new_fov, FOV_LOWER_LIMIT * DEG_TO_RAD)
		|| is_higher(new_fov, FOV_UPPER_LIMIT * DEG_TO_RAD))
		return (ERROR);
	camera->fov = new_fov;
	camera_set_viewport(camera, &camera->viewport);
	return (SUCCESS);
}
