/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rt_object_option_format.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:52:37 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/16 19:40:22 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "identifer_and_parameter.h"
#include "define.h"
#include "parse.h"
#include <stdbool.h>
#include <stddef.h>

static bool	_is_option_key(const char *option_key)
{
	if (ft_is_equal_str(option_key, K_AMBIENT_OMITTED)
		|| ft_is_equal_str(option_key, K_DIFFUSE_OMITTED)
		|| ft_is_equal_str(option_key, K_SPECULAR_OMITTED)
		|| ft_is_equal_str(option_key, K_SHININESS_OMITTED))
		return (true);
	else if (MODE != MODE_MANDATORY)
	{
		if (ft_is_equal_str(option_key, K_REFLECT_OMITTED)
			|| ft_is_equal_str(option_key, BUMP_MAP_OMITTED)
			|| ft_is_equal_str(option_key, IMAGE_MAP_OMITTED))
			return (true);
	}
	else
		return (false);
}

int	check_rt_object_option_format(const t_vla *rt_object)
{
	size_t		idx;
	char		**strings;
	const char	*prev_option_key;

	sort_rt_object_options(rt_object);
	prev_option_key = NULL;
	idx = 1;
	while (idx < rt_object->size)
	{
		strings = rt_object->array[idx++];
		if (!_is_option_key(strings[1])
			|| is_dupulicate(prev_option_key, strings[1]))
			return (ERROR);
		prev_option_key = strings[1];
	}
	return (SUCCESS);
}
