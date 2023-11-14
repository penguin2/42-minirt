/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_light_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 20:28:29 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/13 21:40:26 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcolor.h"
#include "parse.h"
#include "define.h"

int	add_light_color(const t_json_node *light_node, t_light *light)
{
	if (select_json_node(light_node, COLORS) == NULL)
	{
		light->color = color_white();
		return (SUCCESS);
	}
	return (list_to_color(get_list(light_node, COLORS, 3), &light->color));
}
