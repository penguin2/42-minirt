/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_dict_generator_from_lights.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:32:55 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/30 19:59:16 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generator.h"
#include "identifer_and_parameter.h"

void	json_dict_generator_from_lights(t_vla *lights, t_vla *dict)
{
	t_json_node	*light_json_node;

	light_json_node = convert_lights_to_json_dict(
			lights, ID_AMBIENT, LIGHT_ID_AMBIENT, ambient_generator);
	if (light_json_node != NULL)
		ft_vla_append(dict, light_json_node);
	light_json_node = convert_lights_to_json_dict(
			lights, ID_SPOT, LIGHT_ID_SPOT, spot_generator);
	if (light_json_node != NULL)
		ft_vla_append(dict, light_json_node);
}
