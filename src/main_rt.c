/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_rt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:23:03 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/19 13:57:04 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "parse.h"
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

static void	_print_json_file(const char *rt_file)
{
	char	*json_file;
	int		fd;
	char	*line;

	json_file = convert_extension(rt_file, RT_EXTENSION, JSON_EXTENSION);
	fd = try_open_file(json_file, JSON_EXTENSION, O_READ);
	free(json_file);
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
		return (EXIT_FAILURE);
	else
	{
		_print_json_file(argv[1]);
		return (EXIT_SUCCESS);
	}
}
