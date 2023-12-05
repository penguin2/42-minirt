/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_generator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:38:10 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/02 14:30:28 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generator.h"
#include "ambient.h"
#include "identifer_and_parameter.h"

t_vla	*json_ambient_generator(t_light *light)
{
	const t_ambient	*ambient = light->ptr;
	t_vla			*json_ambient;

	json_ambient = ft_vla_new();
	ft_vla_append(
		json_ambient,
		double_to_json_value_node(ambient->brightness, BRIGHTNESS)
		);
	ft_vla_append(
		json_ambient,
		color_to_json_list_node(&light->color, COLORS)
		);
	return (json_ambient);
}
