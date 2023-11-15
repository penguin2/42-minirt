/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_object_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:17:49 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/13 20:26:16 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "define.h"

int	add_object_color(const t_json_node *json_node, t_object *object)
{
	return (list_to_color(get_list(json_node, COLORS, 3), &object->color));
}
