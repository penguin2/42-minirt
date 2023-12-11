/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_get_checkerboard_color.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 01:23:23 by taekklee          #+#    #+#             */
/*   Updated: 2023/12/11 16:29:25 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "libcolor.h"
#include "sphere.h"
#include "utils.h"
#include <math.h>

/**
 * @brief  given the specific position in the sphere,
 * 			calculate the color of its position
 * 
 * 		the white/black part of the checkerboard is defined such that
 * 		1. white/black is alternating 'CHECKERBOARD_FREQUENCY_CYCLE' times
 * 			per one cycle along the latitude
 * 		2. white/black is alternating 'CHECKERBOARD_FREQUENCY_CYCLE' times
 * 			per one cycle along the longitude
 * @param cylinder given cylinder
 * @param pos given position
 * @return white if the position is on the white part, otherwise black
 */
t_color	sphere_get_checkerboard_color(const t_sphere *sphere, t_vec3 pos)
{
	const t_vec3	local_pos = cartesian_system_map_from_standard(
			&sphere->system,
			vec3_sub(pos, sphere->center));
	double			u;
	double			v;

	map_3d_to_spherical(&u, &v, local_pos);
	if (is_odd_2d(
			u * SPHERE_LONGITUDE_CYCLE,
			v * SPHERE_LATITUDE_CYCLE))
		return (color_white());
	return (color_black());
}
