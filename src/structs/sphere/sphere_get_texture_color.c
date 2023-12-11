/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_get_texture_color.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 19:09:59 by taekklee          #+#    #+#             */
/*   Updated: 2023/12/11 16:29:07 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cartesian_system.h"
#include "ppm_reader.h"
#include "sphere.h"
#include "utils.h"

t_color	sphere_get_texture_color(
			const t_sphere *sphere,
			const t_ppm_reader *texture_map,
			t_vec3 pos)
{
	const t_vec3	local_pos = cartesian_system_map_from_standard(
			&sphere->system,
			vec3_sub(pos, sphere->center));
	double			u;
	double			v;

	map_3d_to_spherical(&u, &v, local_pos);
	return (ppm_reader_get_color(texture_map, u, v));
}
