/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_get_checkerboard_color.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 01:35:24 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/17 19:40:46 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "cylinder.h"
#include "utils.h"
#include <math.h>

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
	if (is_odd_2d(theta * 10 / PI, y * 10 / PI / cylinder->radius))
		return (color_white());
	return (color_black());
	return (color_white());
}
