/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_horizontal_rotate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:46:49 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/24 17:39:55 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "utils.h"

void	camera_horizontal_rotate(t_camera *camera, double theta)
{
	rotate_orthogonal_two_vecs_clockwise(&camera->right, &camera->dir, theta);
	camera_set_viewport(&camera->viewport, camera);
}
