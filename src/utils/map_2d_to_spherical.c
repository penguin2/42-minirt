/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_2d_to_spherical.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:30:00 by taekklee          #+#    #+#             */
/*   Updated: 2023/12/01 17:10:41 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include <math.h>

void	map_2d_to_spherical(double *u, double x, double y, double radius)
{
	double	theta;

	theta = acos(x / radius);
	if (y < 0)
		theta = -theta;
	*u = 0.5 * (1 + theta * DIV_PI);
}
