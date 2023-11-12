/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spot_get_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:31:37 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/13 17:57:26 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcolor.h"
#include "libvec3.h"
#include "ray.h"
#include "spot.h"
#include "utils.h"
#include <math.h>
#include <stdbool.h>
#include <stddef.h>

static bool	_is_spot_blocked(
				t_vec3 hit_to_spot,
				const t_hit *hit,
				const t_vla *objects);

t_color	spot_get_color(
			const t_light *light,
			const t_hit *hit,
			const t_vla *objects)
{
	const t_spot	*spot = light->ptr;
	t_vec3			hit_to_spot;
	double			i_diffuse;
	double			i_specular;

	hit_to_spot = vec3_sub(spot->pos, hit->pos);
	if (_is_spot_blocked(hit_to_spot, hit, objects))
		return (color_black());
	hit_to_spot = vec3_unit(hit_to_spot);
	i_diffuse = hit->object->material.k_diffuse
		* vec3_dot(hit->normal, hit_to_spot);
	i_specular = vec3_dot(
			vec3_reflected(hit->incoming_ray.dir, hit->normal),
			hit_to_spot);
	if (i_specular > 0)
		i_specular = hit->object->material.k_specular
			* pow(i_specular, hit->object->material.k_shininess);
	else
		i_specular = 0;
	return (color_mul(color_composite(hit->object->color, spot->color),
			spot->brightness * (i_diffuse + i_specular)));
}

static bool	_is_spot_blocked(
				t_vec3 hit_to_spot,
				const t_hit *hit,
				const t_vla *objects)
{
	const double	dist_hit_to_spot = vec3_len(hit_to_spot);
	double			dist_hit_to_object;
	const t_object	*object;
	size_t			object_idx;
	t_ray			ray_hit_to_spot;

	if (vec3_dot(hit->normal, hit_to_spot) < EPS)
		return (true);
	ray_hit_to_spot = ray_create(hit->pos, hit_to_spot);
	object_idx = 0;
	while (object_idx < objects->size)
	{
		object = objects->array[object_idx];
		if (object->get_dist(object, ray_hit_to_spot, &dist_hit_to_object)
			&& dist_hit_to_object < dist_hit_to_spot)
			return (true);
		++object_idx;
	}
	return (false);
}
