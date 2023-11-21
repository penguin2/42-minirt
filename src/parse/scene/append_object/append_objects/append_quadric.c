/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_quadric.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:18:23 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/21 16:05:26 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec3.h"
#include "quadric.h"
#include "define.h"
#include "parse.h"
#include <float.h>

static int	_try_json_node_to_quadric_coefficient(const t_json_node *node,
													t_quadric *quadric)
{
	if (query_set_double(
			query_create(node, K_A, &quadric->coeff_array[COEFF_A], true),
			range_create(-DBL_MAX, DBL_MAX)) == ERROR
		|| query_set_double(
			query_create(node, K_B, &quadric->coeff_array[COEFF_B], true),
			range_create(-DBL_MAX, DBL_MAX)) == ERROR
		|| query_set_double(
			query_create(node, K_C, &quadric->coeff_array[COEFF_C], true),
			range_create(-DBL_MAX, DBL_MAX)) == ERROR
		|| query_set_double(
			query_create(node, K_D, &quadric->coeff_array[COEFF_D], true),
			range_create(-DBL_MAX, DBL_MAX)) == ERROR
		|| query_set_double(
			query_create(node, K_E, &quadric->coeff_array[COEFF_E], true),
			range_create(-DBL_MAX, DBL_MAX)) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int	append_quadric(const t_json_node *node, t_vla *objects)
{
	t_quadric	quadric;

	if (query_set_vec3(
			query_create(node, COORDINATES, &quadric.center, true),
			range_create(-DBL_MAX, DBL_MAX)) == ERROR
		|| _try_json_node_to_quadric_coefficient(node, &quadric) == ERROR)
		return (ERROR);
	ft_vla_append(
		objects, quadric_object_new(quadric.center, quadric.coeff_array));
	return (SUCCESS);
}
