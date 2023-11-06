/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_generator_from_rt_object.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:56:58 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/06 14:47:40 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include "define.h"
#include "generator.h"
#include <fcntl.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

static void	_put_rt_objects(t_vla *rt_objects, int fd)
{
	size_t	idx;
	t_vla	*rt_object;
	char	*prev_object_identifer;

	ft_putendl_fd(GENERATOR_DICT_START, fd);
	idx = 0;
	while (idx < rt_objects->size)
	{
		rt_object = rt_objects->array[idx++];
	}
	ft_putendl_fd(GENERATOR_DICT_END, fd);
}

int	json_generator_from_rt_objects(t_vla *rt_objects, const char *file)
{
	char	*json_file;
	int		fd;

	json_file = convert_extension(file, ".rt", ".json");
	fd = try_open_file(json_file, ".json", (O_CREAT | O_WRONLY));
	free(json_file);
	if (fd == ERROR)
		return (ERROR);
	_put_rt_objects(rt_objects, fd);
	close(fd);
	return (SUCCESS);
}
