/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_vec3_unit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:11:19 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/08 15:47:54 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec3.h"
#include "define.h"
#include "utils.h"
#include "parse.h"
#include "message_parse.h"
#include <math.h>
#include <stdbool.h>

static bool	_is_normalized(t_vec3 vec)
{
	const double	pow_x = pow(vec.x, 2.0);
	const double	pow_y = pow(vec.y, 2.0);
	const double	pow_z = pow(vec.z, 2.0);
	const double	sum = pow_x + pow_y + pow_z;

	if (is_zero(sum))
		return (false);
	else
		return (sqrt(sum) == 1.0);
}

int	try_vec3_unit(t_vec3 *vec)
{
	if (is_zero(vec->x) && is_zero(vec->y) && is_zero(vec->z))
	{
		print_error(VECTOR_TOO_SMALL);
		return (ERROR);
	}
	if (!_is_normalized(*vec))
		print_warning(WARNING_NORMALIZED);
	*vec = vec3_unit(*vec);
	return (SUCCESS);
}
