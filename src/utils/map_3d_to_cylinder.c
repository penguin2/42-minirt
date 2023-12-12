/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_3d_to_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:30:36 by taekklee          #+#    #+#             */
/*   Updated: 2023/12/11 15:33:32 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "libvec3.h"
#include <math.h>

void	map_3d_to_cylinder(double *u, double *v, t_vec3 pos)
{
	const double	radius_proj = sqrt(pos.x * pos.x + pos.y * pos.y);
	double			theta;

	theta = acos(pos.x / radius_proj);
	if (pos.y < 0)
		theta = -theta;
	*u = pos.z;
	*v = 0.5 * (1 + theta * DIV_PI);
}
