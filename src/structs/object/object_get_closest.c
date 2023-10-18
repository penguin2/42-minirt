/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_get_closest.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:31:10 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/18 11:23:54 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include <float.h>

const t_object	*object_get_closest(t_ray ray, t_vla *objects)
{
	t_object		**objs;
	const t_object	*min_dist_obj;
	size_t			i;
	double			min_dist_to_object;
	double			dist;

	objs = (t_object **)objects->array;
	i = 0;
	min_dist_to_object = DBL_MAX;
	dist = DBL_MAX;
	min_dist_obj = NULL;
	while (i < objects->size)
	{
		if (objs[i]->get_dist(objs[i], ray, &dist) && dist < min_dist_to_object)
		{
			min_dist_to_object = dist;
			min_dist_obj = objs[i];
		}
		++i;
	}
	return (min_dist_obj);
}
