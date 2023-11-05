/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_rt_object_to_json.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:56:58 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/05 20:01:00 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "define.h"
#include "generator.h"
#include <fcntl.h>

int	convert_rt_object_to_json(t_vla *rt_objects, const char *file)
{
	const int	fd = try_open_file(file, ".json", (O_CREAT | O_WRONLY));

	if (fd == ERROR)
		return (ERROR);
	ft_putstr_fd(GENERATOR_DICT_START, fd);
	return (SUCCESS);
}
