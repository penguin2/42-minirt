/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_vec3_unit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:11:19 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/14 20:32:44 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec3.h"
#include "define.h"
#include "utils.h"
#include "parse.h"
#include "message_parse.h"
#include <stdbool.h>

int	try_vec3_unit(t_vec3 *vec)
{
	if (is_zero(vec->x) && is_zero(vec->y) && is_zero(vec->z))
	{
		print_error(VECTOR_TOO_SMALL);
		return (ERROR);
	}
	if (!is_normalized(*vec))
		print_warning(WARNING_NORMALIZED);
	*vec = vec3_unit(*vec);
	return (SUCCESS);
}
