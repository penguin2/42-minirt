/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_viewport_ray.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:51:50 by taekklee          #+#    #+#             */
/*   Updated: 2023/12/11 12:27:26 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "libvec3.h"
#include "ray.h"

t_ray	get_viewport_ray(const t_camera *camera, int height_idx, int width_idx)
{
	t_vec3	target_pos;

	target_pos = vec3_add(
			camera->viewport.upper_left,
			vec3_add(
				vec3_mul(camera->viewport.dw, width_idx),
				vec3_mul(camera->viewport.dh, height_idx)
				)
			);
	return (ray_from_to(camera->eye, target_pos));
}
