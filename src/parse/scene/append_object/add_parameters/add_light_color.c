/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_light_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 20:28:29 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/24 02:06:33 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcolor.h"
#include "parse.h"
#include "define.h"

int	add_light_color(const t_json_node *light_node, t_light *light)
{
	return (
		query_set_color(
			query_create(light_node, COLORS, &light->color, false)
		)
	);
}
