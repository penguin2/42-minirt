/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:33:41 by taekklee          #+#    #+#             */
/*   Updated: 2023/12/08 21:16:57 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "scene.h"
#include "message_parse.h"
#include "utils.h"
#include "parse.h"
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	t_scene	scene;
	t_vla	*json_object;
	int		success_or_error;

	if (argc != 2)
	{
		print_error(ARGC_IS_NOT_EQUAL_2);
		return (EXIT_FAILURE);
	}
	json_object = convert_json_to_json_object(argv[1]);
	if (json_object == NULL)
		return (EXIT_FAILURE);
	success_or_error = json_object_to_scene(json_object, &scene);
	free_json_object(json_object);
	if (success_or_error == ERROR)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
