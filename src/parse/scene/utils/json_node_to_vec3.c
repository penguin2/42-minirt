/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_node_to_vec3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:30:54 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/21 15:47:38 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include "range.h"
#include "define.h"

int	json_node_to_vec3(const t_json_node *node, t_range range, t_vec3 *val)
{
	const t_vla	*list = node->value;

	if (try_json_node_tof(list->array[0], &val->x) == ERROR
		|| try_json_node_tof(list->array[1], &val->y) == ERROR
		|| try_json_node_tof(list->array[2], &val->z) == ERROR)
		return (ERROR);
	else if (is_between_min_to_max(val->x, range.start, range.end)
		&& is_between_min_to_max(val->y, range.start, range.end)
		&& is_between_min_to_max(val->z, range.start, range.end))
		return (SUCCESS);
	else
		return (ERROR);
}
