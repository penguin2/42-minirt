/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generator_plane_object.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:30:47 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/13 16:38:30 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generator.h"
#include "identifer_and_parameter.h"
#include <stdbool.h>
#include <stddef.h>

void	generator_plane_object(t_vla *plane, int fd)
{
	const char	**strings = plane->array[0];
	size_t		idx;

	idx = 1;
	if (strings[idx] != NULL)
		put_key_and_list(COORDINATES, strings[idx++], false, fd);
	if (strings[idx] != NULL)
		put_key_and_list(NORMAL, strings[idx++], true, fd);
	if (strings[idx] != NULL)
		put_key_and_list(COLORS, strings[idx++], true, fd);
	put_options(plane, fd);
}
