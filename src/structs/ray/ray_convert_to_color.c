/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_convert_to_color.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 21:29:22 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/12 22:19:11 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit.h"
#include "libvec3.h"
#include "ray.h"

/**
 * @brief tracing the given ray,
 * 		if the ray hits a certain object, it calculates the color of that hit.
 *
 * @param ray given ray to trace
 * @param scene information of the scene
 * @param recursion_depth current depth when calling this function recursively
 * @return color of the hit if the ray hits a certain object,
 * 		otherwise the default color (black!?)
 */
t_color	ray_convert_to_color(t_ray ray, t_scene *scene, int recursion_depth)
{
	t_color		color;
	t_hit		*hit;

	if (recursion_depth >= RT_MAX_RECURSION_DEPTH)
		return (color_black());
	hit = hit_new(ray, &scene->objects);
	if (hit == NULL)
		return (color_black());
	color = hit_get_color(hit, &scene->objects, &scene->lights);
	if (hit->object->material.is_reflective)
		color = color_mix(
				ray_convert_to_color(
					ray_create(hit->pos, vec3_reflected(ray.dir, hit->normal)),
					scene,
					recursion_depth + 1),
				color,
				hit->object->material.k_reflect);
	hit_free(hit);
	return (color);
}
