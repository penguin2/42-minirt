/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:23:03 by taekklee          #+#    #+#             */
/*   Updated: 2023/12/09 19:49:31 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "mlx_ptr.h"
#include "scene.h"
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	t_scene	scene;
	int		success_or_error;

	if (scene_init(&scene, argc, argv) == ERROR)
		return (EXIT_FAILURE);
	success_or_error = mlx_ptr_main(&scene);
	scene_free(&scene);
	if (success_or_error == ERROR)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
