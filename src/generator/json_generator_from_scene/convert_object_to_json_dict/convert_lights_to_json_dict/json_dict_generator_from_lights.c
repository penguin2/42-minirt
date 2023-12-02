/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_dict_generator_from_lights.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:32:55 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/02 15:27:42 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generator.h"
#include "identifer_and_parameter.h"

void	json_dict_generator_from_lights(t_vla *lights, t_vla *dict)
{
	t_json_node	*json_light_dict;

	json_light_dict = convert_lights_to_json_dict(
			lights, ID_AMBIENT, LIGHT_ID_AMBIENT, json_ambient_generator);
	if (json_light_dict != NULL)
		ft_vla_append(dict, json_light_dict);
	json_light_dict = convert_lights_to_json_dict(
			lights, ID_SPOT, LIGHT_ID_SPOT, json_spot_generator);
	if (json_light_dict != NULL)
		ft_vla_append(dict, json_light_dict);
}
