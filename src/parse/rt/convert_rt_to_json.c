/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_rt_to_json.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:17:20 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/24 20:05:29 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include "generator.h"
#include "define.h"
#include "utils.h"
#include "message_parse.h"
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

/**
* @brief Convert from the rt extension to the json extension
*		 and open the file.
*
* @param rt_file rt extension file.
*
* @return if true if the file is opened successfully,
*		  false otherwise.
*/
static int	_try_open_converted_extension_json_file(const char *rt_file)
{
	char	*json_file;
	int		json_fd;

	json_file = convert_extension(rt_file, RT_EXTENSION, JSON_EXTENSION);
	json_fd = try_open_file(json_file, JSON_EXTENSION, O_WRITE);
	if (json_fd == ERROR)
		print_error(INVALID_FILE_EXTENSION);
	free(json_file);
	return (json_fd);
}

static int	_try_generate_json(t_vla *rt_objects_array, const char *file)
{
	const int	json_fd = _try_open_converted_extension_json_file(file);

	if (json_fd == ERROR)
		return (ERROR);
	json_generator_from_rt_objects_array(rt_objects_array, json_fd);
	close(json_fd);
	return (SUCCESS);
}

int	convert_rt_to_json(const char *file)
{
	const int	rt_fd = try_open_file(file, RT_EXTENSION, O_READ);
	t_vla		rt_objects_array;
	int			success_or_error;

	if (rt_fd == ERROR)
		return (ERROR);
	ft_vla_init(&rt_objects_array);
	success_or_error = convert_rt_to_rt_objects_array(&rt_objects_array, rt_fd);
	close(rt_fd);
	if (success_or_error == SUCCESS)
	{
		success_or_error = _try_generate_json(&rt_objects_array, file);
		free_rt_objects_array(&rt_objects_array);
	}
	return (success_or_error);
}
