/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_get_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:18:17 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/18 17:29:12 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit.h"
#include "libcolor.h"

t_color	hit_get_color(t_hit *hit, t_vla *objects, t_vla *lights)
{
	(void)objects;
	(void)lights;
	(void)hit;
	return (color_create(0.5, 0.5, 1.0));
}
