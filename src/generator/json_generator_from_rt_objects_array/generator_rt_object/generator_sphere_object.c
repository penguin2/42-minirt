/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generator_sphere_object.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:30:47 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/24 20:20:49 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generator.h"
#include "identifer_and_parameter.h"
#include <stdbool.h>
#include <stddef.h>

void	generator_sphere_object(t_vla *sphere, int fd)
{
	const char	**strings = sphere->array[0];
	size_t		idx;

	idx = 1;
	if (strings[idx] != NULL)
		put_key_and_list(COORDINATES, strings[idx++], false, fd);
	if (strings[idx] != NULL)
		put_key_and_value(DIAMETER, strings[idx++], true, fd);
	if (strings[idx] != NULL)
		put_key_and_list(COLORS, strings[idx++], true, fd);
	put_options(sphere, fd);
}
