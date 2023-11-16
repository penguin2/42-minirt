/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_spot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:04:15 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/17 01:51:53 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "spot.h"
#include "parse.h"
#include "message_parse.h"
#include "define.h"
#include "light.h"
#include "utils.h"

int	append_spot(const t_json_node *node, t_vla *lights)
{
	t_spot				spot;
	const t_json_node	*brightness_node = select_json_node(node, BRIGHTNESS);
	const t_vla			*list_pos = get_list(node, COORDINATES, 3);

	if (json_node_to_double(brightness_node, &spot.brightness, 0, 1) == ERROR
		|| list_to_vec3(list_pos, &spot.pos, NO_LIMIT, NO_LIMIT) == ERROR)
		return (ERROR);
	ft_vla_append(lights, spot_light_new(spot.pos, spot.brightness));
	return (SUCCESS);
}
