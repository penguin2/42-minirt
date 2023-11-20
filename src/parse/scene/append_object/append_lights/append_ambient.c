/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_ambient.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 21:27:09 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/20 21:34:26 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ambient.h"
#include "parse.h"
#include "define.h"
#include "light.h"

int	append_ambient(const t_json_node *node, t_vla *lights)
{
	t_ambient			ambient;

	if (query_set_double(
			query_create(node, BRIGHTNESS, &ambient.brightness, true),
			range_create(0.0, 1.0)) == ERROR)
		return (ERROR);
	ft_vla_append(lights, ambient_light_new(ambient.brightness));
	return (SUCCESS);
}
