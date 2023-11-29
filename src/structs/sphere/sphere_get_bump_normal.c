/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_get_bump_normal.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:19:56 by taekklee          #+#    #+#             */
/*   Updated: 2023/12/01 01:34:11 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cartesian_system.h"
#include "libvec3.h"
#include "sphere.h"
#include "utils.h"

static void	_set_local_system(
				t_cartesian_system *local_system,
				const t_cartesian_system *sphere_system,
				t_vec3 normal);

t_vec3	sphere_get_bump_normal(
			const t_sphere *sphere,
			const t_ppm_reader *bump_map,
			t_vec3 pos,
			t_vec3 normal)
{
	const t_vec3		local_pos = cartesian_system_map_from_standard(
			&sphere->system,
			vec3_sub(pos, sphere->center));
	double				u;
	double				v;
	t_vec3				bump_normal;
	t_cartesian_system	local_system;

	map_3d_to_spherical(&u, &v, local_pos, sphere->radius);
	bump_normal = ppm_reader_get_normal(bump_map, u, v);
	_set_local_system(&local_system, &sphere->system, normal);
	return (cartesian_system_map_to_standard(&local_system, bump_normal));
}

static void	_set_local_system(
				t_cartesian_system *local_system,
				const t_cartesian_system *sphere_system,
				t_vec3 normal)
{
	const double	dot_normal_z = vec3_dot(sphere_system->axis_z, normal);

	if (is_zero(dot_normal_z - 1.0))
	{
		local_system->axis_x = sphere_system->axis_x;
		local_system->axis_y = sphere_system->axis_y;
		local_system->axis_z = sphere_system->axis_z;
	}
	else if (is_zero(dot_normal_z + 1.0))
	{
		local_system->axis_x = vec3_mul(sphere_system->axis_x, -1.0);
		local_system->axis_y = vec3_mul(sphere_system->axis_y, -1.0);
		local_system->axis_z = vec3_mul(sphere_system->axis_z, -1.0);
	}
	else
	{
		local_system->axis_y = vec3_unit(
				vec3_projected(sphere_system->axis_z, normal));
		local_system->axis_z = normal;
		local_system->axis_x = vec3_cross(
				local_system->axis_y,
				local_system->axis_z);
	}
}
