/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:23:03 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/02 21:47:18 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "minirt.h"
#include "mlx_ptr.h"
#include "scene.h"
#include <stdlib.h>

// int	main(int argc, char *argv[])
// {
// 	t_scene	scene;
// 
// 	if (scene_init(&scene, argc, argv) == ERROR
// 		|| mlx_ptr_main(&scene) == ERROR)
// 		return (EXIT_FAILURE);
// 	return (EXIT_SUCCESS);
// }

// json object to scene
int	main(int argc, char *argv[])
{
	t_scene	scene;

	if (scene_init(&scene, argc, argv) == ERROR)
		return (1);
	return (0);
}

// json to json object
// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include "parse.h"
// #include "generator.h"
// int main(int argc, char **argv)
// {
// 	t_vla		*json_object;
// 
// 	if (argc != 2) {
// 		printf("argc != 2\n");
// 		return (EXIT_FAILURE);
// 	}
// 	json_object = convert_json_to_json_object(argv[1]);
// 	if (json_object == NULL) {
// 		return (1);
// 	}
// 	else {
// 		json_generator(json_object->array[0], 0, STDOUT_FILENO);
// 		free_json_object(json_object);
// 		return (0);
// 	}
// }
// 	__attribute__((destructor)) static void destructor()
// {
//    system("leaks -q miniRT");
// }
