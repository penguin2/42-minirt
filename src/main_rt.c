/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_rt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:23:03 by taekklee          #+#    #+#             */
/*   Updated: 2023/12/14 17:09:54 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "libgnl.h"
#include "parse.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

static void	_print_json_file(const char *file)
{
	char	*json_file;
	int		fd;
	char	*line;

	if (check_extension(file, RT_EXTENSION) == SUCCESS)
		json_file = convert_extension(file, RT_EXTENSION, JSON_EXTENSION);
	else
		json_file = ft_strdup(file);
	fd = try_open_file(json_file, JSON_EXTENSION, O_READ);
	free(json_file);
	if (fd == ERROR)
		return ;
	while (1)
	{
		line = get_next_line(fd, NULL, GNL_MODE_NEWLINE);
		if (line == NULL)
			break ;
		printf("%s\n", line);
		free(line);
	}
	get_next_line(fd, NULL, GNL_MODE_RESET);
	close(fd);
}

int	main(int argc, char *argv[])
{
	t_scene	scene;

	if (scene_init(&scene, argc, argv) == ERROR)
		return (EXIT_FAILURE);
	_print_json_file(argv[1]);
	scene_free(&scene);
	return (EXIT_SUCCESS);
}
