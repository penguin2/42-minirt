/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_node_to_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:30:54 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/24 01:49:52 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "parse.h"

int	json_node_to_color(const t_json_node *node, t_color *val)
{
	const t_vla		*list = node->value;
	const t_range	range_0_255 = range_create(0, MAX_COLOR_8BIT);

	if (json_node_to_double(
			list->array[0], range_0_255, &val->red) == ERROR
		|| json_node_to_double(
			list->array[1], range_0_255, &val->green) == ERROR
		|| json_node_to_double(
			list->array[2], range_0_255, &val->blue) == ERROR)
		return (ERROR);
	val->red /= MAX_COLOR_8BIT;
	val->green /= MAX_COLOR_8BIT;
	val->blue /= MAX_COLOR_8BIT;
	return (SUCCESS);
}
