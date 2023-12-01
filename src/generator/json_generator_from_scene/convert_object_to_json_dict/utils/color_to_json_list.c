/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_to_json_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:23:20 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/01 19:54:32 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "generator.h"
#include "libcolor.h"

t_json_node	*color_to_json_list(const t_color *color, const char *key)
{
	t_json_node	*list_node;
	t_vla		*list;

	list_node = json_node_new(ft_strdup(key), ft_vla_new(), NODE_LIST);
	list = list_node->value;
	ft_vla_append(list,
		double_to_json_list(color->red * MAX_COLOR_8BIT, NULL));
	ft_vla_append(list,
		double_to_json_list(color->green * MAX_COLOR_8BIT, NULL));
	ft_vla_append(list,
		double_to_json_list(color->blue * MAX_COLOR_8BIT, NULL));
	return (list_node);
}
