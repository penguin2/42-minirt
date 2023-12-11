/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_get_texture_color.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:47:14 by taekklee          #+#    #+#             */
/*   Updated: 2023/12/11 15:30:22 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"
#include "define.h"
#include "plane.h"
#include "ppm_reader.h"
#include "utils.h"

t_color	cylinder_get_texture_color(
			const t_cylinder *cylinder,
			const t_ppm_reader *texture_map,
			t_vec3 pos)
{
	const t_vec3	local_pos = cartesian_system_map_from_standard(
			&cylinder->system,
			vec3_sub(pos, cylinder->center));
	double			u;
	double			v;

	map_3d_to_cylinder(&u, &v, local_pos);
	u = mod_double(u / (2.0 * cylinder->radius * PI) * CYLINDER_CYCLE);
	v = mod_double(v * CYLINDER_CYCLE);
	return (ppm_reader_get_color(texture_map, u, v));
}
