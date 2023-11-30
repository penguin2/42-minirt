/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spot_generator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:38:10 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/30 16:38:58 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generator.h"
#include "light.h"
#include "spot.h"
#include "identifer_and_parameter.h"
#include <stddef.h>

t_vla	*spot_generator(t_light *light)
{
	const t_spot	*spot = light->ptr;
	t_vla			*json_spot_object;

	json_spot_object = ft_vla_new();
	ft_vla_append(json_spot_object,
		vec3_to_json_list(&spot->pos, COORDINATES));
	ft_vla_append(json_spot_object,
		double_to_json_list(spot->brightness, BRIGHTNESS));
	ft_vla_append(json_spot_object,
		color_to_json_list(&light->color, COLORS));
	return (json_spot_object);
}
