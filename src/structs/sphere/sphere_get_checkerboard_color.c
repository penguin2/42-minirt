/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_get_checkerboard_color.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 01:23:23 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/17 19:30:53 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "libcolor.h"
#include "sphere.h"
#include "utils.h"
#include <math.h>

t_color	sphere_get_checkerboard_color(const t_sphere *sphere, t_vec3 pos)
{
	const t_vec3	coord = vec3_sub(pos, sphere->center);
	const double	radius_proj = sqrt(coord.z * coord.z + coord.x * coord.x);
	double			phi;
	double			theta;

	phi = acos(coord.y / sphere->radius);
	theta = acos(coord.z / radius_proj);
	if (coord.x < 0)
		theta = -theta;
	if (is_odd_2d(phi * 10 / PI, theta * 10 / PI))
		return (color_white());
	return (color_black());
}
