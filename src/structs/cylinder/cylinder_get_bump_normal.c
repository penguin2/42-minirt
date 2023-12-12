/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_get_bump_normal.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:41:25 by taekklee          #+#    #+#             */
/*   Updated: 2023/12/11 16:42:24 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cartesian_system.h"
#include "cylinder.h"
#include "define.h"
#include "libvec3.h"
#include "utils.h"

static void	_set_local_system(
				t_cartesian_system *local_system,
				const t_cartesian_system *sphere_system,
				t_vec3 normal);

t_vec3	cylinder_get_bump_normal(
			const t_cylinder *cylinder,
			const t_ppm_reader *bump_map,
			t_vec3 pos,
			t_vec3 normal)
{
	const t_vec3		local_pos = cartesian_system_map_from_standard(
			&cylinder->system,
			vec3_sub(pos, cylinder->center));
	double				u;
	double				v;
	t_vec3				bump_normal;
	t_cartesian_system	local_system;

	map_3d_to_cylinder(&u, &v, local_pos);
	u = mod_double(u / (2.0 * PI * cylinder->radius) * CYLINDER_CYCLE);
	v = mod_double(v * CYLINDER_CYCLE);
	bump_normal = ppm_reader_get_normal(bump_map, u, v);
	_set_local_system(&local_system, &cylinder->system, normal);
	return (cartesian_system_map_to_standard(&local_system, bump_normal));
}

static void	_set_local_system(
				t_cartesian_system *local_system,
				const t_cartesian_system *cylinder_system,
				t_vec3 normal)
{
	local_system->axis_y = cylinder_system->axis_z;
	local_system->axis_z = normal;
	local_system->axis_x = vec3_cross(
			local_system->axis_y,
			local_system->axis_z);
}
