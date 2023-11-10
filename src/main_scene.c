/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:33:41 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/10 16:41:29 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "minirt.h"
#include "mlx_ptr.h"
#include "scene.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "generator.h"

int	main(int argc, char *argv[])
{
	t_scene	scene;

	if (scene_init(&scene, argc, argv) == ERROR)
		exit (1);
	else
		exit (0);
}
