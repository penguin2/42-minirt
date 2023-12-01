/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_get_checkerboard_color.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 01:11:13 by taekklee          #+#    #+#             */
/*   Updated: 2023/12/01 16:52:55 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "plane.h"
#include "utils.h"

/**
 * @brief  given the specific position in the plane,
 * 			calculate the color of its position
 * 
 * 		the white/black part of the checkerboard is defined such that
 * 		every part is square-shaped with the size 'CHECKERBOARD_SIZE_PLANE'
 * @param cylinder given cylinder
 * @param pos given position
 * @return white if the position is on the white part, otherwise black
 */
t_color	plane_get_checkerboard_color(const t_plane *plane, t_vec3 pos)
{
	const t_vec3	coord = vec3_sub(pos, plane->origin);
	const double	u = vec3_dot(coord, plane->system.axis_x)
		/ UNIT_TEXTURE_SIZE;
	const double	v = vec3_dot(coord, plane->system.axis_y)
		/ UNIT_TEXTURE_SIZE;

	if (is_odd_2d(u, v))
		return (color_white());
	return (color_black());
}
