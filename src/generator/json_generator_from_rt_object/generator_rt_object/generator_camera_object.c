/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generator_camera_object.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:30:47 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/11 18:17:44 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generator.h"
#include <stdbool.h>

bool	generator_camera_object(t_vla *camera, int fd)
{
	const char		**strings = camera->array[0];
	const size_t	strings_size = ft_strings_len(strings);

	if (1 == strings_size)
		return (false);
	if (2 <= strings_size)
		put_key_and_list("coordinates", strings[1], false, fd);
	if (3 <= strings_size)
		put_key_and_list("orientation", strings[2], true, fd);
	if (4 <= strings_size)
		put_key_and_value("fov", strings[3], true, fd);
	return (true);
}
