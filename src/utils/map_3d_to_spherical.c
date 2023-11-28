/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_3d_to_spherical.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:31:47 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/29 01:45:46 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "libvec3.h"
#include "utils.h"
#include <math.h>

void	map_3d_to_spherical(double *u, double *v, t_vec3 pos, double radius)
{
	const double	radius_proj = sqrt(pos.z * pos.z + pos.x * pos.x);
	double			phi;
	double			theta;

	phi = acos(pos.y / radius);
	if (is_zero(radius_proj))
		theta = 0;
	else
		theta = acos(pos.z / radius_proj);
	if (pos.x < 0)
		theta = -theta;
	*u = phi * DIV_PI;
	*v = 0.5 * (1 + theta * DIV_PI);
}
