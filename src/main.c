/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:23:03 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/10 16:35:20 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "minirt.h"
#include "mlx_ptr.h"
#include "scene.h"
#include "parse.h"
#include <stdlib.h>

// int	main(int argc, char *argv[])
// {
// 	t_scene	scene;

// 	if (scene_init(&scene, argc, argv) == ERROR
// 		|| mlx_ptr_main(&scene) == ERROR)
// 		return (EXIT_FAILURE);
// 	return (EXIT_SUCCESS);
// }

int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (1);
	else if (convert_rt_to_json(argv[1]) == ERROR)
		return (1);
	else
		return (0);
}
// 	__attribute__((destructor)) static void destructor()
// {
//    system("leaks -q miniRT");
// }
