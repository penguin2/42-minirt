/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_quadric.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:18:23 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/17 02:09:25 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec3.h"
#include "quadric.h"
#include "define.h"
#include "parse.h"

static int	_try_json_node_to_quadric_coefficient(const t_json_node *node,
													t_quadric *quadric)
{
	const t_json_node	*k_a_node = select_json_node(node, K_A);
	const t_json_node	*k_b_node = select_json_node(node, K_B);
	const t_json_node	*k_c_node = select_json_node(node, K_C);
	const t_json_node	*k_d_node = select_json_node(node, K_D);
	const t_json_node	*k_e_node = select_json_node(node, K_E);

	if (json_node_to_double(k_a_node,
			&quadric->coeff_array[COEFF_A], NO_LIMIT, NO_LIMIT) == ERROR
		|| json_node_to_double(k_b_node,
			&quadric->coeff_array[COEFF_B], NO_LIMIT, NO_LIMIT) == ERROR
		|| json_node_to_double(k_c_node,
			&quadric->coeff_array[COEFF_C], NO_LIMIT, NO_LIMIT) == ERROR
		|| json_node_to_double(k_d_node,
			&quadric->coeff_array[COEFF_D], NO_LIMIT, NO_LIMIT) == ERROR
		|| json_node_to_double(k_e_node,
			&quadric->coeff_array[COEFF_E], NO_LIMIT, NO_LIMIT) == ERROR)
		return (ERROR);
	else
		return (SUCCESS);
}

int	append_quadric(const t_json_node *node, t_vla *objects)
{
	t_quadric	quadric;

	if (list_to_vec3(get_list(node, COORDINATES, 3),
			&quadric.center, NO_LIMIT, NO_LIMIT) == ERROR
		|| _try_json_node_to_quadric_coefficient(node, &quadric) == ERROR)
		return (ERROR);
	ft_vla_append(
		objects, quadric_object_new(quadric.center, quadric.coeff_array));
	return (SUCCESS);
}
