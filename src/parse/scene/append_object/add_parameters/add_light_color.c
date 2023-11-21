/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_light_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 20:28:29 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/21 16:27:45 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcolor.h"
#include "parse.h"
#include "define.h"

int	add_light_color(const t_json_node *light_node, t_light *light)
{
	if (select_json_node(light_node, COLORS) == NULL)
	{
		light->color = color_white();
		return (SUCCESS);
	}
	return (
		query_set_color(
			query_create(light_node, COLORS, &light->color, true)
		));
}
