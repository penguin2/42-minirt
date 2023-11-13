/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:04:57 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/13 16:27:16 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "generator.h"
#include "identifer_and_parameter.h"
#include <stddef.h>

static const char	*_get_formal_option_key(const char *simplified_option_key)
{
	if (ft_is_equal_str(simplified_option_key, K_AMBIENT_OMITTED))
		return (K_AMBIENT);
	else if (ft_is_equal_str(simplified_option_key, K_DIFFUSE_OMITTED))
		return (K_DIFFUSE);
	else if (ft_is_equal_str(simplified_option_key, K_SPECULAR_OMITTED))
		return (K_SPECULAR);
	else if (ft_is_equal_str(simplified_option_key, K_SHININESS_OMITTED))
		return (K_SHININESS);
	else
		return (simplified_option_key);
}

void	put_options(t_vla *rt_object, int fd)
{
	size_t		idx;
	const char	**option;
	const char	*formal_option_key;

	if (rt_object->size == 1)
		return ;
	idx = 1;
	while (idx < rt_object->size)
	{
		ft_putendl_fd(GENERATOR_COMMA, fd);
		option = rt_object->array[idx++];
		formal_option_key = _get_formal_option_key(option[1]);
		put_key_and_value(formal_option_key, option[2], false, fd);
	}
}
