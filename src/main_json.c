/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_json.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:33:47 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/23 22:31:51 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "utils.h"
#include "generator.h"
#include "message_parse.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	t_vla		*json_object;

	if (argc != 2)
	{
		print_error(ARGC_IS_NOT_EQUAL_2);
		exit (EXIT_FAILURE);
	}
	json_object = convert_json_to_json_object(argv[1]);
	if (json_object == NULL)
		exit (EXIT_FAILURE);
	else
	{
		json_generator_from_json_object(
			json_object->array[0],
			0,
			STDOUT_FILENO);
		free_json_object(json_object);
		exit (EXIT_SUCCESS);
	}
}
