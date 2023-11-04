/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_color_parameter.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:17:49 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/04 15:37:42 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generator.h"
#include "define.h"

int	add_color_parameter(const t_json_node *json_node, t_object *object)
{
	return (list_to_color(get_list(json_node, COLORS, 3), &object->color));
}
