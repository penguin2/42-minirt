/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_rt_to_json.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:17:20 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/09 20:09:57 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include "define.h"
#include <stddef.h>
#include <unistd.h>
#include <fcntl.h>

static void	_free_content_of_rt_object(t_vla *rt_objects)
{
	size_t	idx;
	size_t	idx2;
	t_vla	*rt_object;

	idx = 0;
	while (idx < rt_objects->size)
	{
		rt_object = rt_objects->array[idx++];
		idx2 = 0;
		while (idx2 < rt_object->size)
			ft_vla_free(rt_object->array[idx2++], ft_free_strings);
	}
}

int	convert_rt_to_json(const char *file)
{
	const int	fd = try_open_file(file, ".rt", O_RDONLY);
	t_vla		rt_objects;
	int			success_or_error;

	if (fd == ERROR)
		return (ERROR);
	ft_vla_init(&rt_objects);
	if (convert_rt_to_rt_object(&rt_objects, fd) == SUCCESS)
		success_or_error = SUCCESS;
	else
		success_or_error = ERROR;
	close(fd);
	_free_content_of_rt_object(&rt_objects);
	ft_vla_free(&rt_objects, NULL);
	return (success_or_error);
}
