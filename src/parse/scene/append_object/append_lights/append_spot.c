/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_spot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:04:15 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/13 16:34:28 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "spot.h"
#include "parse.h"
#include "message_parse.h"
#include "define.h"
#include "light.h"
#include "utils.h"

static void	_append_spot_light(t_spot spot, t_vla *lights)
{
	t_spot	*new_spot;
	t_light	*light;

	new_spot = spot_new(spot.pos, spot.brightness, spot.color);
	light = light_new(new_spot, spot_get_color, spot_free);
	ft_vla_append(lights, light);
}

int	append_spot(const t_json_node *node, t_vla *lights)
{
	t_spot				spot;
	const t_json_node	*brightness_node = select_json_node(node, BRIGHTNESS);
	const t_vla			*list_pos = get_list(node, COORDINATES, 3);

	if (json_node_to_double(brightness_node, &spot.brightness, 0, 1) == ERROR
		|| list_to_vec3(list_pos, &spot.pos, NO_LIMIT, NO_LIMIT) == ERROR)
		return (ERROR);
	if (MODE == MODE_MANDATORY)
		spot.color = color_create(1, 1, 1);
	else if (MODE == MODE_BONUS
		&& list_to_color(get_list(node, COLORS, 3), &spot.color) == ERROR)
	{
		print_warning(WARNING_SPOT_COLORS);
		spot.color = color_create(1, 1, 1);
	}
	_append_spot_light(spot, lights);
	return (SUCCESS);
}
