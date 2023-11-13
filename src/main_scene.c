/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:33:41 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/13 18:47:37 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "minirt.h"
#include "mlx_ptr.h"
#include "scene.h"
#include "generator.h"
#include "message_parse.h"
#include "utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	main(int argc, char *argv[])
{
	t_scene	scene;
	t_vla	*json_object;
	int		success_or_error;

	if (argc != 2)
	{
		print_error(ARGC_IS_NOT_EQUAL_2);
		return (ERROR);
	}
	json_object = convert_json_to_json_object(argv[1]);
	if (json_object == NULL)
		return (1);
	success_or_error = json_object_to_scene(json_object, &scene);
	free_json_object(json_object);
	if (success_or_error == ERROR)
		exit(1);
	else
		exit(0);
}
// 	__attribute__((destructor)) static void destructor()
// {
//    system("leaks -q miniRT");
// }
