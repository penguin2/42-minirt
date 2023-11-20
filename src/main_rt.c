/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_rt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:23:03 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/20 21:33:58 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "parse.h"
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

static void	_print_json_file(const char *file)
{
	char	*json_file;
	int		fd;
	char	*line;

	if (check_extension(file, RT_EXTENSION) == SUCCESS)
	{
		json_file = convert_extension(file, RT_EXTENSION, JSON_EXTENSION);
		fd = try_open_file(json_file, JSON_EXTENSION, O_READ);
		free(json_file);
	}
	else
		fd = try_open_file(file, JSON_EXTENSION, O_READ);
	if (fd == ERROR)
		return ;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("%s", line);
		free(line);
	}
}

int	main(int argc, char *argv[])
{
	t_scene	scene;

	if (scene_init(&scene, argc, argv) == ERROR)
		exit (EXIT_FAILURE);
	else
	{
		_print_json_file(argv[1]);
		exit (EXIT_SUCCESS);
	}
}
