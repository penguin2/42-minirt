/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_get_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:23:40 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/05 16:32:55 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ambient.h"

t_color	ambient_get_color(
			const t_light *light,
			const t_hit *hit,
			const t_vla *objects)
{
	const t_ambient	*ambient = light->ptr;

	return (color_mul(
			ambient->color,
			hit->object->material.k_ambient * ambient->brightness));
	(void)objects;
}
