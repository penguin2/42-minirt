/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_get_checkerboard_color.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 01:11:13 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/17 18:28:52 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "plane.h"
#include "utils.h"

t_color	plane_get_checkerboard_color(const t_plane *plane, t_vec3 pos)
{
	const t_vec3	coord = vec3_sub(pos, plane->origin);
	const double	u = vec3_dot(coord, plane->axis_u);
	const double	v = vec3_dot(coord, plane->axis_v);

	if (is_odd_2d(u / 30, v / 30))
		return (color_white());
	return (color_black());
}
