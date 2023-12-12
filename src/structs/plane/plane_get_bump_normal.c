/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_get_bump_normal.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 00:57:38 by taekklee          #+#    #+#             */
/*   Updated: 2023/12/01 12:41:52 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "plane.h"
#include "utils.h"

t_vec3	plane_get_bump_normal(
			const t_plane *plane,
			const t_ppm_reader *bump_map,
			t_vec3 pos,
			t_vec3 normal)
{
	const t_vec3	coord = vec3_sub(pos, plane->origin);
	const double	u = mod_double(vec3_dot(coord, plane->system.axis_x)
			/ UNIT_TEXTURE_SIZE);
	const double	v = mod_double(vec3_dot(coord, plane->system.axis_y)
			/ UNIT_TEXTURE_SIZE);
	t_vec3			bump_normal;

	(void)normal;
	bump_normal = ppm_reader_get_normal(bump_map, u, v);
	return (cartesian_system_map_to_standard(&plane->system, bump_normal));
}
