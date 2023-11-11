/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generator_ambient_object.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:30:47 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/11 16:37:13 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generator.h"
#include <stdbool.h>
#include <stddef.h>

bool	generator_ambient_object(t_vla *ambient, int fd)
{
	const char		**strings = ambient->array[0];
	const size_t	strings_size = ft_strings_len(strings);

	if (1 == strings_size)
		return (false);
	if (2 <= strings_size)
		put_key_and_value("brightness", strings[1], false, fd);
	if (3 <= strings_size)
		put_key_and_list("colors", strings[2], true, fd);
	return (true);
}
