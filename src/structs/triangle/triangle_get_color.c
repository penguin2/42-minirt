/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_get_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 01:30:00 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/17 01:30:25 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "triangle.h"

t_color	triangle_get_color(const t_object *object, const t_hit *hit)
{
	(void)object;
	(void)hit;
	return (object->color);
}
