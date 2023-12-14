/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_normalized.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 20:31:02 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/14 20:31:52 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec3.h"
#include "utils.h"
#include <stdbool.h>
#include <math.h>

bool	is_normalized(t_vec3 vec)
{
	const double	pow_x = pow(vec.x, 2.0);
	const double	pow_y = pow(vec.y, 2.0);
	const double	pow_z = pow(vec.z, 2.0);
	const double	sum = pow_x + pow_y + pow_z;

	return (is_zero(sqrt(sum) - 1.0));
}
