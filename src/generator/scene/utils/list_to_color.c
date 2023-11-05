/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:50:20 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/05 14:59:18 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcolor.h"
#include "generator.h"
#include "define.h"
#include "utils.h"

int	list_to_color(const t_vla *list, t_color *color)
{
	if (list == NULL || list->size != 3 || !is_only_value_node(list))
	{
		print_error(INVALID_COLORS);
		return (ERROR);
	}
	else if (try_json_node_tof(list->array[0], &color->red) == ERROR
		|| try_json_node_tof(list->array[1], &color->green) == ERROR
		|| try_json_node_tof(list->array[2], &color->blue) == ERROR)
		return (ERROR);
	if (is_between_min_to_max(color->red, 0.0, 255.0)
		&& is_between_min_to_max(color->green, 0.0, 255.0)
		&& is_between_min_to_max(color->blue, 0.0, 255.0))
		return (SUCCESS);
	else
		return (ERROR);
}
