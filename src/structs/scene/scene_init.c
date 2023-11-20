/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:39:21 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/20 20:46:00 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "parse.h"
#include "utils.h"
#include "message_parse.h"
#include <stdlib.h>

static t_vla	*_generate_json_object(const char *file)
{
	char	*json_file;
	t_vla	*json_object;

	if (MODE == MODE_MANDATORY
		|| check_extension(file, RT_EXTENSION) == SUCCESS)
	{
		if (convert_rt_to_json(file) == ERROR)
			return (NULL);
		json_file = convert_extension(file, RT_EXTENSION, JSON_EXTENSION);
		json_object = convert_json_to_json_object(json_file);
		free(json_file);
	}
	else if (MODE == MODE_BONUS)
		json_object = convert_json_to_json_object(file);
	else
		return (NULL);
	return (json_object);
}

int	scene_init(t_scene *scene, int argc, char **argv)
{
	t_vla	*json_object;
	int		success_or_error;

	if (argc != 2)
	{
		print_error(ARGC_IS_NOT_EQUAL_2);
		return (ERROR);
	}
	json_object = _generate_json_object(argv[1]);
	if (json_object == NULL)
		return (ERROR);
	success_or_error = json_object_to_scene(json_object, scene);
	free_json_object(json_object);
	return (success_or_error);
}
