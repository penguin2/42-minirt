/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_rt_to_json.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:17:20 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/12 21:31:02 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include "generator.h"
#include "define.h"
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int	convert_rt_to_json(const char *file)
{
	const int	fd = try_open_file(file, ".rt", O_RDONLY);
	t_vla		rt_objects;
	int			success_or_error;

	if (fd == ERROR)
		return (ERROR);
	ft_vla_init(&rt_objects);
	success_or_error = convert_rt_to_rt_object(&rt_objects, fd);
	close(fd);
	if (success_or_error == SUCCESS)
		json_generator_from_rt_object(&rt_objects, STDOUT_FILENO);
	free_rt_object(&rt_objects, success_or_error == SUCCESS);
	return (success_or_error);
}
