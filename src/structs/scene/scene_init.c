/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:39:21 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/13 17:54:45 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "parse.h"
#include "utils.h"
#include "message_parse.h"

int	scene_init(t_scene *scene, int argc, char **argv)
{
	t_vla	*json_object;
	int		success_or_error;
	char	*json_file;

	if (argc != 2)
	{
		print_error(ARGC_IS_NOT_EQUAL_2);
		return (ERROR);
	}
	if (convert_rt_to_json(argv[1]))
		return (ERROR);
	json_file = convert_extension(argv[1], RT_EXTENSION, JSON_EXTENSION);
	json_object = convert_json_to_json_object(json_file);
	free(json_file);
	if (json_object == NULL)
		return (ERROR);
	success_or_error = json_object_to_scene(json_object, scene);
	free_json_object(json_object);
	return (success_or_error);
}
