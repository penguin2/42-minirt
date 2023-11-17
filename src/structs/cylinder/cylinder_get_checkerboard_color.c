/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_get_checkerboard_color.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 01:35:24 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/17 20:44:36 by taekklee         ###   ########.fr       */
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
 * 		1. white/black is alternating 'CHECKERBOARD_FREQUENCY_CYCLE' times
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
	const t_vec3	coord = vec3_sub(pos, cylinder->center);
	const double	y = vec3_dot(coord, cylinder->dir);
	const double	z = vec3_dot(coord, cylinder->axis_u);
	const double	x = vec3_dot(coord, cylinder->axis_v);
	double			theta;

	theta = acos(z / cylinder->radius);
	if (x < 0)
		theta = -theta;
	if (is_odd_2d(
			theta * CHECKERBOARD_FREQUENCY_CYCLE / PI,
			y * CHECKERBOARD_FREQUENCY_CYCLE / PI / cylinder->radius))
		return (color_white());
	return (color_black());
}
