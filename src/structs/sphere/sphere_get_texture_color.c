/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_get_texture_color.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 19:09:59 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/27 10:01:56 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ppm_reader.h"
#include "sphere.h"
#include "utils.h"

t_color	sphere_get_texture_color(
			const t_sphere *sphere,
			const t_ppm_reader *texture_map,
			t_vec3 pos)
{
	double	u;
	double	v;

	map_3d_to_spherical(&u, &v, vec3_sub(pos, sphere->center), sphere->radius);
	return (ppm_reader_get_color(texture_map, u, v));
}
