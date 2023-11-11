/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:04:57 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/11 16:36:23 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "generator.h"
#include <stddef.h>

static const char	*_get_formal_option_key(const char *simplified_option_key)
{
	if (ft_is_equal_str(simplified_option_key, "amb"))
		return ("coefficient-ambient");
	else if (ft_is_equal_str(simplified_option_key, "dif"))
		return ("coefficient-diffuse");
	else if (ft_is_equal_str(simplified_option_key, "spc"))
		return ("coefficient-specular");
	else if (ft_is_equal_str(simplified_option_key, "shi"))
		return ("shininess");
	else
		return (simplified_option_key);
}

void	put_options(t_vla *rt_object, bool is_with_comma, int fd)
{
	size_t		idx;
	const char	**option;
	const char	*formal_option_key;

	if (is_with_comma && rt_object->size != 1)
		ft_putendl_fd(GENERATOR_COMMA, fd);
	idx = 1;
	while (idx < rt_object->size)
	{
		option = rt_object->array[idx++];
		formal_option_key = _get_formal_option_key(option[1]);
		put_key_and_value(formal_option_key, option[2], false, fd);
		if (idx != rt_object->size)
			ft_putendl_fd(GENERATOR_COMMA, fd);
	}
}
