/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_get_texture_color.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 23:15:03 by taekklee          #+#    #+#             */
/*   Updated: 2023/12/01 17:16:35 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "plane.h"
#include "utils.h"

t_color	plane_get_texture_color(
			const t_plane *plane,
			const t_ppm_reader *texture_map,
			t_vec3 pos)
{
	const t_vec3	coord = vec3_sub(pos, plane->origin);
	const double	u = vec3_dot(coord, plane->system.axis_x)
		/ UNIT_TEXTURE_SIZE;
	const double	v = vec3_dot(coord, plane->system.axis_y)
		/ UNIT_TEXTURE_SIZE;

	return (ppm_reader_get_color(
			texture_map,
			mod_double(u),
			mod_double(v)));
}
