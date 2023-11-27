/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_get_checkerboard_color.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 01:23:23 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/17 20:29:43 by taekklee         ###   ########.fr       */
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
	const t_vec3	coord = vec3_sub(pos, sphere->center);
	const double	radius_proj = sqrt(coord.z * coord.z + coord.x * coord.x);
	double			phi;
	double			theta;

	phi = acos(coord.y / sphere->radius);
	theta = acos(coord.z / radius_proj);
	if (coord.x < 0)
		theta = -theta;
	if (is_odd_2d(
			phi * CHECKERBOARD_FREQUENCY_CYCLE / PI,
			theta * CHECKERBOARD_FREQUENCY_CYCLE / PI))
		return (color_white());
	return (color_black());
}
