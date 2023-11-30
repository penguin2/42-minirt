/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_scene_to_json.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:23:03 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/30 18:35:08 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "mlx_ptr.h"
#include "scene.h"
#include "generator.h"
#include <stddef.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	t_scene	scene;

	if (scene_init(&scene, argc, argv) == ERROR
		|| json_generator_from_scene(&scene))
		exit (EXIT_FAILURE);
	exit (EXIT_SUCCESS);
}
