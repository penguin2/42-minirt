/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:23:03 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/05 14:35:58 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "minirt.h"
#include "mlx_ptr.h"
#include "scene.h"
#include <stdlib.h>

// delete !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#include <stdio.h>
#include <unistd.h>
#include "generator.h"
// json object to scene
int	main_scene(int argc, char *argv[])
{
	t_scene	scene;

	if (scene_init(&scene, argc, argv) == ERROR)
		exit (1);
	else
		exit (0);
}

// json to json object
int	main_json(int argc, char **argv)
{
	t_vla		*json_object;

	if (argc != 2)
	{
		printf("argc != 2\n");
		return (EXIT_FAILURE);
	}
	json_object = convert_json_to_json_object(argv[1]);
	if (json_object == NULL)
		exit (1);
	else
	{
		json_generator(json_object->array[0], 0, STDOUT_FILENO);
		free_json_object(json_object);
		exit (0);
	}
}

int	main(int argc, char *argv[])
{
	t_scene	scene;

	if (MODE == MODE_MANDATORY || MODE == MODE_BONUS)
	{
		if (scene_init(&scene, argc, argv) == ERROR
			|| mlx_ptr_main(&scene) == ERROR)
			return (EXIT_FAILURE);
		return (EXIT_SUCCESS);
	}
	else if (MODE == MODE_JSON)
		main_json(argc, argv);
	else if (MODE == MODE_SCENE)
		main_scene(argc, argv);
}

// 	__attribute__((destructor)) static void destructor()
// {
//    system("leaks -q miniRT");
// }
