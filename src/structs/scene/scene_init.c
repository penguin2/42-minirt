/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:39:21 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/20 16:24:20 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "cylinder.h"
#include "define.h"
#include "libft.h"
#include "libvec3.h"
#include "plane.h"
#include "scene.h"
#include "sphere.h"
#include <math.h>
#include <stdbool.h>

static void	_temp_objects_and_lights(t_vla *lights, t_vla *objects);

int	scene_init(t_scene *scene, int argc, char **argv)
{
	(void)argc;
	(void)argv;
	camera_init(&scene->camera);
	ft_vla_init(&scene->objects);
	ft_vla_init(&scene->lights);
	_temp_objects_and_lights(&scene->lights, &scene->objects);
	return (SUCCESS);
}

static void	_temp_objects_and_lights(t_vla *lights, t_vla *objects)
{
	(void)lights;
	ft_vla_append(objects, object_new(
			plane_new(vec3_create(0, -10, -10), vec3_create(0, 1, 0)),
			plane_get_dist, plane_get_normal, plane_free));
	ft_vla_append(objects, object_new(
			cylinder_new(vec3_create(-10, 0, -10), vec3_create(1, 1, 1), 1, 3),
			cylinder_get_dist, cylinder_get_normal, cylinder_free));
	ft_vla_append(objects, object_new(
			sphere_new(vec3_create(-5, 0, -10), 2),
			sphere_get_dist, sphere_get_normal, sphere_free));
	ft_vla_append(objects, object_new(
			cylinder_new(vec3_create(5, 0, -10), vec3_create(-1, 0, 1), 1, 3),
			cylinder_get_dist, cylinder_get_normal, cylinder_free));
	ft_vla_append(objects, object_new(
			cylinder_new(vec3_create(0, 0, -10), vec3_create(0, 0, 1), 1, 3),
			cylinder_get_dist, cylinder_get_normal, cylinder_free));
	ft_vla_append(objects, object_new(
			sphere_new(vec3_create(10, 0, -10), 2),
			sphere_get_dist, sphere_get_normal, sphere_free));
}
