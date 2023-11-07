/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_vec3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:50:20 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/07 20:41:42 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generator.h"
#include "message_generator.h"
#include "define.h"
#include "utils.h"

int	list_to_vec3(const t_vla *list, t_vec3 *vec3, double min, double max)
{
	if (list == NULL || list->size != 3 || !is_only_value_node(list))
	{
		print_error(INVALID_VECTOR);
		return (ERROR);
	}
	else if (try_json_node_tof(list->array[0], &vec3->x) == ERROR
		|| try_json_node_tof(list->array[1], &vec3->y) == ERROR
		|| try_json_node_tof(list->array[2], &vec3->z) == ERROR)
		return (ERROR);
	else if (is_between_min_to_max(vec3->x, min, max)
		&& is_between_min_to_max(vec3->y, min, max)
		&& is_between_min_to_max(vec3->z, min, max))
		return (SUCCESS);
	else
		return (ERROR);
}
