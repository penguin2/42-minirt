/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_get_texture_color.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 23:15:03 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/27 10:05:56 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "plane.h"
#include <math.h>

static double	_convert_zero_to_one(double x);

t_color	plane_get_texture_color(
			const t_plane *plane,
			const t_ppm_reader *texture_map,
			t_vec3 pos)
{
	const t_vec3	coord = vec3_sub(pos, plane->origin);
	const double	u = vec3_dot(coord, plane->axis_u);
	const double	v = vec3_dot(coord, plane->axis_v);

	return (ppm_reader_get_color(
			texture_map,
			_convert_zero_to_one(u / UNIT_TEXTURE_SIZE),
			_convert_zero_to_one(v / UNIT_TEXTURE_SIZE)));
}

static double	_convert_zero_to_one(double x)
{
	double	tmp;

	x = modf(x, &tmp);
	if (x < 0)
		return (x + 1);
	return (x);
}
