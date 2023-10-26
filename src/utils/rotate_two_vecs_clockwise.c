/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_two_vecs_clockwise.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:54:00 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/26 18:58:57 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec3.h"
#include <math.h>

void	rotate_two_vecs_clockwise(
			t_vec3 *u, t_vec3 *v, double theta)
{
	const double	cos_theta = cos(theta);
	const double	sin_theta = sin(theta);
	const t_vec3	prev_u = *u;
	const t_vec3	prev_v = *v;

	*u = vec3_add(vec3_mul(prev_u, cos_theta), vec3_mul(prev_v, sin_theta));
	*v = vec3_add(vec3_mul(prev_u, -sin_theta), vec3_mul(prev_v, cos_theta));
}
