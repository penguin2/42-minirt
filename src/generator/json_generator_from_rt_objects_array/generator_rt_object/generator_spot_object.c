/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generator_spot_object.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:30:47 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/16 20:19:15 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generator.h"
#include "identifer_and_parameter.h"
#include "utils.h"
#include "message_parse.h"
#include <stdbool.h>
#include <stddef.h>

void	generator_spot_object(t_vla *spot, int fd)
{
	const char	**strings = spot->array[0];
	size_t		idx;

	idx = 1;
	if (strings[idx] != NULL)
		put_key_and_list(COORDINATES, strings[idx++], false, fd);
	if (strings[idx] != NULL)
		put_key_and_value(BRIGHTNESS, strings[idx++], true, fd);
	if (strings[idx] != NULL)
		put_key_and_list(COLORS, strings[idx++], true, fd);
	else
		print_warning(WARNING_LIGHT_COLORS);
}
