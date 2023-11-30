/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_to_json_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:23:20 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/21 20:50:24 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "parse.h"
#include "libcolor.h"

static t_json_node	*_new_color_node(double color)
{
	return (
		json_node_new(
			NULL,
			ft_ftoa(
				color * MAX_COLOR_8BIT,
				DOUBLE_LIMIT_DIGIT
			),
			NODE_VALUE
		)
	);
}

t_json_node	*color_to_json_list(const t_color *color, const char *key)
{
	t_json_node	*list_node;
	t_vla		*list;

	list_node = json_node_new(ft_strdup(key), ft_vla_new(), NODE_LIST);
	list = list_node->value;
	ft_vla_append(list, _new_color_node(color->red));
	ft_vla_append(list, _new_color_node(color->green));
	ft_vla_append(list, _new_color_node(color->blue));
	return (list_node);
}
