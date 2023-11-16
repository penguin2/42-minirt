/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_ambient.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 21:27:09 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/17 01:50:33 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ambient.h"
#include "parse.h"
#include "define.h"
#include "light.h"

int	append_ambient(const t_json_node *node, t_vla *lights)
{
	t_ambient			ambient;
	const t_json_node	*brightness_node = select_json_node(node, BRIGHTNESS);

	if (json_node_to_double(
			brightness_node, &ambient.brightness, 0, 1) == ERROR)
		return (ERROR);
	ft_vla_append(lights, ambient_light_new(ambient.brightness));
	return (SUCCESS);
}
