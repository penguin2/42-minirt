/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:39:21 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/12 16:10:37 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "define.h"
#include "libft.h"
#include "libvec3.h"
#include "scene.h"
#include <math.h>
#include <stdbool.h>

static void		_temp_objects_and_lights(t_vla *lights, t_vla *objects);

int	scene_init(t_scene *scene, int argc, char **argv)
{
	(void)argc;
	(void)argv;
	camera_init(&scene->camera);
	_temp_objects_and_lights(&scene->lights, &scene->objects);
	return (SUCCESS);
}

static void	_temp_objects_and_lights(t_vla *lights, t_vla *objects)
{
	(void)lights;
	(void)objects;
}

