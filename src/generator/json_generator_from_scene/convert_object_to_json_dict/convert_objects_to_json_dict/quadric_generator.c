/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadric_generator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:47:16 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/02 14:28:58 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generator.h"
#include "object.h"
#include "quadric.h"
#include "identifer_and_parameter.h"

t_vla	*quadric_generator(t_object *object)
{
	const t_quadric	*quadric = object->ptr;
	t_vla			*json_quadric;

	json_quadric = ft_vla_new();
	ft_vla_append(json_quadric,
		vec3_to_json_list_node(&quadric->center, COORDINATES));
	ft_vla_append(json_quadric,
		double_to_json_value_node(quadric->coeff_array[COEFF_A], K_A));
	ft_vla_append(json_quadric,
		double_to_json_value_node(quadric->coeff_array[COEFF_B], K_B));
	ft_vla_append(json_quadric,
		double_to_json_value_node(quadric->coeff_array[COEFF_C], K_C));
	ft_vla_append(json_quadric,
		double_to_json_value_node(quadric->coeff_array[COEFF_D], K_D));
	ft_vla_append(json_quadric,
		double_to_json_value_node(quadric->coeff_array[COEFF_E], K_E));
	ft_vla_append(json_quadric,
		color_to_json_list_node(&object->color, COLORS));
	return (json_quadric);
}
