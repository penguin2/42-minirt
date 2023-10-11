/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:23:03 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/11 18:43:20 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "minirt.h"
#include "scene.h"
#include <stdlib.h>

int	mlx_main(t_scene *scene);

int	main(int argc, char *argv[])
{
	t_scene	scene;

	if (scene_init(&scene, argc, argv) == ERROR
		|| mlx_main(&scene) == ERROR)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
