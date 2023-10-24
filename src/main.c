/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:23:03 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/24 15:32:27 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "minirt.h"
#include "mlx_ptr.h"
#include "scene.h"
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	t_scene	scene;

	if (scene_init(&scene, argc, argv) == ERROR
		|| mlx_ptr_main(&scene) == ERROR)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include "parse.h"
// int main(int argc, char **argv)
// {
// 	t_vla		*json_object;

// 	if (argc != 3) {
// 		printf("argc != 3\n");
// 		return (EXIT_FAILURE);
// 	}
// 	json_object = convert_json_to_json_object(argv[1]);
// 	if (json_object == NULL) {
// 		return (atoi(argv[2]) == 0);
// 	}
// 	else {
// 		json_generator(json_object, 1);
// 		return (atoi(argv[2]) == 1);
// 	}
// }
