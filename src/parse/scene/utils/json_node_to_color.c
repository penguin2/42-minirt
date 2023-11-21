/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_node_to_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:30:54 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/21 15:58:36 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include "range.h"
#include "define.h"

int	json_node_to_color(const t_json_node *node, t_color *val)
{
	const t_vla	*list = node->value;

	if (try_json_node_tof(list->array[0], &val->red) == ERROR
		|| try_json_node_tof(list->array[1], &val->green) == ERROR
		|| try_json_node_tof(list->array[2], &val->blue) == ERROR)
		return (ERROR);
	else if (is_between_min_to_max(val->red, 0.0, MAX_COLOR_8BIT)
		&& is_between_min_to_max(val->green, 0.0, MAX_COLOR_8BIT)
		&& is_between_min_to_max(val->blue, 0.0, MAX_COLOR_8BIT))
	{
		val->red /= MAX_COLOR_8BIT;
		val->green /= MAX_COLOR_8BIT;
		val->blue /= MAX_COLOR_8BIT;
		return (SUCCESS);
	}
	else
		return (ERROR);
}
