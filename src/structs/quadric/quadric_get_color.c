/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadric_get_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 01:27:08 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/17 01:27:52 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quadric.h"

t_color	quadric_get_color(const t_object *object, const t_hit *hit)
{
	(void)object;
	(void)hit;
	return (object->color);
}
