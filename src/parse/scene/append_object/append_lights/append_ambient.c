/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_ambient.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 21:27:09 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/12 23:52:26 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ambient.h"
#include "parse.h"
#include "define.h"
#include "light.h"

static void	_append_ambient_light(t_ambient ambient, t_vla *lights)
{
	t_ambient	*new_ambient;
	t_light		*light;

	new_ambient = ambient_new(ambient.brightness, ambient.color);
	light = light_new(new_ambient, ambient_get_color, ambient_free);
	ft_vla_append(lights, light);
}

int	append_ambient(const t_json_node *node, t_vla *lights)
{
	t_ambient			ambient;
	const t_json_node	*brightness_node = select_json_node(node, BRIGHTNESS);

	if (json_node_to_double(brightness_node, &ambient.brightness, 0, 1) == ERROR
		|| list_to_color(get_list(node, COLORS, 3), &ambient.color) == ERROR)
		return (ERROR);
	_append_ambient_light(ambient, lights);
	return (SUCCESS);
}
