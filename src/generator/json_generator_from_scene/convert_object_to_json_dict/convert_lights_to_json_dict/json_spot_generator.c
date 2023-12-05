/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spot_generator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:38:10 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/02 14:31:02 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generator.h"
#include "spot.h"
#include "identifer_and_parameter.h"
#include <stddef.h>

t_vla	*json_spot_generator(t_light *light)
{
	const t_spot	*spot = light->ptr;
	t_vla			*json_spot;

	json_spot = ft_vla_new();
	ft_vla_append(json_spot,
		vec3_to_json_list_node(&spot->pos, COORDINATES));
	ft_vla_append(json_spot,
		double_to_json_value_node(spot->brightness, BRIGHTNESS));
	ft_vla_append(json_spot,
		color_to_json_list_node(&light->color, COLORS));
	return (json_spot);
}
