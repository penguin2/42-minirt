/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rt_object_option_format.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:52:37 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/09 19:11:26 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "define.h"
#include "parse.h"
#include <stdbool.h>
#include <stddef.h>

static bool	_is_option_key(const char *option_key)
{
	if (ft_is_equal_str(option_key, "amb")
		|| ft_is_equal_str(option_key, "dif")
		|| ft_is_equal_str(option_key, "spc")
		|| ft_is_equal_str(option_key, "shi")
		|| ft_is_equal_str(option_key, "bmp")
		|| ft_is_equal_str(option_key, "imp"))
		return (true);
	else
		return (false);
}

static int	_check_option_parameters(t_vla *rt_object)
{
	size_t		idx;
	char		**strings;
	const char	*prev_option_key;

	prev_option_key = NULL;
	idx = 1;
	while (idx < rt_object->size)
	{
		strings = rt_object->array[idx++];
		if (!_is_option_key(strings[1])
			|| is_dupulicate(prev_option_key, strings[1]))
			return (ERROR);
	}
	return (SUCCESS);
}

int	check_rt_object_option_format(t_vla *rt_objects)
{
	size_t	idx;
	t_vla	*rt_object;

	idx = 0;
	while (idx < rt_objects->size)
	{
		rt_object = rt_objects->array[idx++];
		if (_check_option_parameters(rt_object) == ERROR)
			return (ERROR);
	}
	return (SUCCESS);
}
