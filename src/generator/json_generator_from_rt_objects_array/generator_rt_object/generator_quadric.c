/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generator_quadric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:30:47 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/16 15:40:50 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generator.h"
#include "identifer_and_parameter.h"
#include <stdbool.h>
#include <stddef.h>

void	generator_quadric_object(t_vla *quadric, int fd)
{
	const char	**strings = quadric->array[0];
	size_t		idx;

	idx = 1;
	if (strings[idx] != NULL)
		put_key_and_list(COORDINATES, strings[idx++], false, fd);
	if (strings[idx] != NULL)
		put_key_and_value(K_A, strings[idx++], true, fd);
	if (strings[idx] != NULL)
		put_key_and_value(K_B, strings[idx++], true, fd);
	if (strings[idx] != NULL)
		put_key_and_value(K_C, strings[idx++], true, fd);
	if (strings[idx] != NULL)
		put_key_and_value(K_D, strings[idx++], true, fd);
	if (strings[idx] != NULL)
		put_key_and_value(K_E, strings[idx++], true, fd);
	if (strings[idx] != NULL)
		put_key_and_list(COLORS, strings[idx++], true, fd);
	put_options(quadric, fd);
}
