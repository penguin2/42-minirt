/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_material_parameters_to_json_obj.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 21:03:23 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/04 21:38:24 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "generator.h"
#include "parse.h"
#include "identifer_and_parameter.h"

void	append_material_parameters_node(t_vla *json_obj, t_material material)
{
	ft_vla_append(json_obj,
		double_to_json_value_node(material.k_ambient, K_AMBIENT));
	ft_vla_append(json_obj,
		double_to_json_value_node(material.k_diffuse, K_DIFFUSE));
	ft_vla_append(json_obj,
		double_to_json_value_node(material.k_specular, K_SPECULAR));
	ft_vla_append(json_obj,
		double_to_json_value_node(material.k_shininess, K_SHININESS));
	if (material.is_reflective)
	{
		ft_vla_append(json_obj,
			bool_to_json_value_node(material.is_reflective, IS_REFLECTIVE));
		ft_vla_append(json_obj,
			double_to_json_value_node(material.k_reflect, K_REFLECT));
	}
}
