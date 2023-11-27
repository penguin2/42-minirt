/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:39:21 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/24 18:26:55 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "parse.h"
#include "utils.h"
#include "message_parse.h"
#include <stdlib.h>

/**
* @brief If the file extension is rt, generate a JSON file from the rt file
*		 and return a string with the modified extension from rt to json.
*		 Else if it is not the case,
*		 and the compilation mode is MODE_MANDATORY, return NULL.
*		 Otherwise, return a string
*		 that is a copy of the file specified in the first argument.
*
* @param file A file with an unknown extension.
*/
static char	*_generate_json_file(const char *file)
{
	if (check_extension(file, RT_EXTENSION) == SUCCESS)
	{
		if (convert_rt_to_json(file) == ERROR)
			return (NULL);
		return (convert_extension(file, RT_EXTENSION, JSON_EXTENSION));
	}
	else if (MODE == MODE_BONUS
		&& check_extension(file, JSON_EXTENSION) == SUCCESS)
		return (ft_strdup(file));
	else
	{
		print_error(INVALID_FILE_EXTENSION);
		return (NULL);
	}
}

int	scene_init(t_scene *scene, int argc, char **argv)
{
	t_vla	*json_object;
	char	*json_file;
	int		success_or_error;

	if (argc != 2)
	{
		print_error(ARGC_IS_NOT_EQUAL_2);
		return (ERROR);
	}
	json_file = _generate_json_file(argv[1]);
	if (json_file == NULL)
		return (ERROR);
	json_object = convert_json_to_json_object(json_file);
	free(json_file);
	if (json_object == NULL)
		return (ERROR);
	success_or_error = json_object_to_scene(json_object, scene);
	free_json_object(json_object);
	return (success_or_error);
}
