/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generator_cylinder_object.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:30:47 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/12 22:32:00 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generator.h"
#include <stdbool.h>

void	generator_cylinder_object(t_vla *cylinder, int fd)
{
	const char		**strings = cylinder->array[0];
	const size_t	strings_size = ft_strings_len(strings);

	if (2 <= strings_size)
		put_key_and_list("coordinates", strings[1], false, fd);
	if (3 <= strings_size)
		put_key_and_list("axis", strings[2], true, fd);
	if (4 <= strings_size)
		put_key_and_value("diameter", strings[3], true, fd);
	if (5 <= strings_size)
		put_key_and_value("height", strings[4], true, fd);
	if (6 <= strings_size)
		put_key_and_list("colors", strings[5], true, fd);
	put_options(cylinder, fd);
}
