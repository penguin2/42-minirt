/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generator_plane_object.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:30:47 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/12 22:32:08 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generator.h"
#include <stdbool.h>

void	generator_plane_object(t_vla *plane, int fd)
{
	const char		**strings = plane->array[0];
	const size_t	strings_size = ft_strings_len(strings);

	if (2 <= strings_size)
		put_key_and_list("coordinates", strings[1], false, fd);
	if (3 <= strings_size)
		put_key_and_list("normal", strings[2], true, fd);
	if (4 <= strings_size)
		put_key_and_list("colors", strings[3], true, fd);
	put_options(plane, fd);
}
