/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_lights_to_ambient_dict.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:38:10 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/30 16:32:53 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generator.h"
#include "light.h"
#include "ambient.h"
#include "identifer_and_parameter.h"
#include <stddef.h>

t_vla	*ambient_generator(t_light *light)
{
	const t_ambient	*ambient = light->ptr;
	t_vla			*json_ambient_object;

	json_ambient_object = ft_vla_new();
	ft_vla_append(json_ambient_object,
		double_to_json_list(ambient->brightness, BRIGHTNESS));
	ft_vla_append(json_ambient_object,
		color_to_json_list(&light->color, COLORS));
	return (json_ambient_object);
}
