/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_spot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:04:15 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/21 16:34:01 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "spot.h"
#include "parse.h"
#include "message_parse.h"
#include "define.h"
#include "light.h"
#include "utils.h"
#include <float.h>

int	append_spot(const t_json_node *node, t_vla *lights)
{
	t_spot				spot;

	if (query_set_vec3(
			query_create(node, COORDINATES, &spot.pos, true),
			range_create(-DBL_MAX, DBL_MAX)) == ERROR
		|| query_set_double(
			query_create(node, BRIGHTNESS, &spot.brightness, true),
			range_create(0.0, 1.0)) == ERROR)
		return (ERROR);
	ft_vla_append(lights, spot_light_new(spot.pos, spot.brightness));
	return (SUCCESS);
}
