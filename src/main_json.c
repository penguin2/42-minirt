/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_json.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:33:47 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/12 23:01:30 by rikeda           ###   ########.fr       */
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

int	main(int argc, char **argv)
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
		json_generator_from_json_object(json_object->array[0], 0, 1);
		free_json_object(json_object);
		exit (0);
	}
}
// 	__attribute__((destructor)) static void destructor()
// {
//    system("leaks -q miniRT");
// }
