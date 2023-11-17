/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generator_triangle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:30:47 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/15 20:00:06 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generator.h"
#include "identifer_and_parameter.h"
#include <stdbool.h>
#include <stddef.h>

void	generator_triangle_object(t_vla *triangle, int fd)
{
	const char	**strings = triangle->array[0];
	size_t		idx;

	idx = 1;
	if (strings[idx] != NULL)
		put_key_and_list(VERTEX1, strings[idx++], false, fd);
	if (strings[idx] != NULL)
		put_key_and_list(VERTEX2, strings[idx++], true, fd);
	if (strings[idx] != NULL)
		put_key_and_list(VERTEX3, strings[idx++], true, fd);
	if (strings[idx] != NULL)
		put_key_and_list(COLORS, strings[idx++], true, fd);
	put_options(triangle, fd);
}
