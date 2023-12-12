/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_get_checkerboard_color.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 01:35:24 by taekklee          #+#    #+#             */
/*   Updated: 2023/12/11 15:39:12 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "cylinder.h"
#include "utils.h"
#include <math.h>

/**
 * @brief  given the specific position in the cylinder,
 * 			calculate the color of its position
 * 
 * 		the white/black part of the checkerboard is defined such that
 * 		1. white/black is alternating 'CYLINDER_CYCLE' times
 * 			per one cycle along the surface of the cylinder
 * 		2. every part should be square-shaped
 * @param cylinder given cylinder
 * @param pos given position
 * @return white if the position is on the white part, otherwise black
 */
t_color	cylinder_get_checkerboard_color(
				const t_cylinder *cylinder,
				t_vec3 pos)
{
	const t_vec3	local_pos = cartesian_system_map_from_standard(
			&cylinder->system,
			vec3_sub(pos, cylinder->center));
	double			u;
	double			v;

	map_3d_to_cylinder(&u, &v, local_pos);
	u = u / (2.0 * PI * cylinder->radius) * CYLINDER_CYCLE;
	v = v * CYLINDER_CYCLE;
	if (is_odd_2d(u, v))
		return (color_white());
	return (color_black());
}
