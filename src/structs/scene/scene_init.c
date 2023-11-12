/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:39:21 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/13 00:41:10 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "libcolor.h"
#include "libft.h"
#include "scene.h"
#include "parse.h"
#include "generator.h"
#include "utils.h"
#include "message_parse.h"
#include <stdbool.h>
#include <stdlib.h>

int	scene_init(t_scene *scene, int argc, char **argv)
{
	t_vla	*json_object;
	int		success_or_error;

	if (argc != 2)
	{
		print_error(ARGC_IS_NOT_EQUAL_2);
		return (ERROR);
	}
	json_object = convert_json_to_json_object(argv[1]);
	if (json_object == NULL)
		return (ERROR);
	ft_vla_init(&scene->objects);
	ft_vla_init(&scene->lights);
	success_or_error = json_object_to_scene(json_object, scene);
	free_json_object(json_object);
	return (success_or_error);
}
