/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_node_to_vec3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:30:54 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/24 01:49:14 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "parse.h"

int	json_node_to_vec3(const t_json_node *node, t_range range, t_vec3 *val)
{
	const t_vla		*list = node->value;

	if (json_node_to_double(list->array[0], range, &val->x) == ERROR
		|| json_node_to_double(list->array[1], range, &val->y) == ERROR
		|| json_node_to_double(list->array[2], range, &val->z) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
