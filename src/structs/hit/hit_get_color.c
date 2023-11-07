/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_get_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:18:17 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/05 17:10:13 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit.h"
#include "libcolor.h"
#include "light.h"
#include <stddef.h>

t_color	hit_get_color(
			const t_hit *hit,
			const t_vla *objects,
			const t_vla *lights)
{
	const t_light	*light;
	size_t			light_idx;
	t_color			color;

	color = color_black();
	light_idx = 0;
	while (light_idx < lights->size)
	{
		light = lights->array[light_idx];
		color = color_add(color, light->get_color(light, hit, objects));
		++light_idx;
	}
	return (color);
}
