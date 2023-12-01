/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_get_texture_color.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:47:14 by taekklee          #+#    #+#             */
/*   Updated: 2023/12/01 17:14:54 by taekklee         ###   ########.fr       */
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
	const t_vec3	coord = vec3_sub(pos, cylinder->center);
	const double	z = vec3_dot(coord, cylinder->system.axis_z)
		/ cylinder->radius * DIV_PI * CYLINDER_CYCLE;
	const double	x = vec3_dot(coord, cylinder->system.axis_x);
	const double	y = vec3_dot(coord, cylinder->system.axis_y);
	double			theta;

	map_2d_to_spherical(&theta, x, y, cylinder->radius);
	theta *= CYLINDER_CYCLE;
	return (ppm_reader_get_color(
			texture_map,
			mod_double(theta),
			mod_double(z)));
}
