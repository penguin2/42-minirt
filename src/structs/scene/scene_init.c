/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:39:21 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/01 17:32:42 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "libft.h"
#include "scene.h"
#include "parse.h"
#include "generator.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int	scene_init(t_scene *scene, int argc, char **argv)
{
	t_vla	*json_object;

	if (argc != 2)
	{
		printf("argc != 2\n");
		return (ERROR);
	}
	json_object = convert_json_to_json_object(argv[1]);
	if (json_object == NULL)
		return (ERROR);
	ft_vla_init(&scene->objects);
	ft_vla_init(&scene->lights);
	if (json_object_to_scene(json_object, scene) == ERROR)
		return (ERROR);
	else
		return (SUCCESS);
}
