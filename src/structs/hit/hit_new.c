/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:15:07 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/18 11:21:49 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit.h"
#include "libft.h"
#include "object.h"

t_hit	*hit_new(t_ray incoming_ray, t_vla *objects)
{
	const t_object	*object;
	t_hit			*new;
	double			dist;

	object = object_get_closest(incoming_ray, objects);
	if (object == NULL)
		return (NULL);
	new = ft_xcalloc(1, sizeof(t_hit));
	new->incoming_ray = incoming_ray;
	new->object = object;
	object->get_dist(object, incoming_ray, &dist);
	new->pos = ray_at(incoming_ray, dist);
	new->normal = object->get_normal(object, incoming_ray, new->pos);
	return (new);
}
