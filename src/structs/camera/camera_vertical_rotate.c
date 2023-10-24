/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_vertical_rotate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:50:25 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/24 17:41:52 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "utils.h"

void	camera_vertical_rotate(t_camera *camera, double theta)
{
	rotate_orthogonal_two_vecs_clockwise(&camera->dir, &camera->up, theta);
	camera_set_viewport(&camera->viewport, camera);
}
