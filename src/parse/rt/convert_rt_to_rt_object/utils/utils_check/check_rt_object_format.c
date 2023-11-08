/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rt_object_format.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 19:32:27 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/11 20:34:34 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include "generator.h"
#include "define.h"
#include <stdbool.h>
#include <stddef.h>

static int	_check_size_of_parameters(const t_vla *rt_object,
										size_t required_parameters_max_size,
										size_t optional_parameters_max_size)
{
	const char	**required_parameters = rt_object->array[0];
	const char	**optional_parameters;
	size_t		idx;

	if (1 == ft_strings_len(required_parameters)
		|| required_parameters_max_size < ft_strings_len(required_parameters)
		|| optional_parameters_max_size < rt_object->size - 1)
		return (ERROR);
	idx = 1;
	while (idx < rt_object->size)
	{
		optional_parameters = rt_object->array[idx++];
		if (ft_strings_len(optional_parameters) != 3
			|| !ft_is_equal_str(optional_parameters[0], OPTION_START))
			return (ERROR);
		sort_rt_object_options(rt_object);
		if (check_rt_object_option_format(rt_object))
			return (ERROR);
	}
	return (SUCCESS);
}

static int	_check_rt_object(t_vla *rt_object)
{
	const char	**strings = rt_object->array[0];
	const char	*identifer = strings[0];

	if (ft_is_equal_str(identifer, "A"))
		return (_check_size_of_parameters(rt_object, 3, 0));
	else if (ft_is_equal_str(identifer, "C"))
		return (_check_size_of_parameters(rt_object, 4, 0));
	else if (ft_is_equal_str(identifer, "L"))
		return (_check_size_of_parameters(rt_object, 4, 0));
	else if (ft_is_equal_str(identifer, "cy"))
		return (_check_size_of_parameters(rt_object, 6, 6));
	else if (ft_is_equal_str(identifer, "pl"))
		return (_check_size_of_parameters(rt_object, 4, 6));
	else if (ft_is_equal_str(identifer, "sp"))
		return (_check_size_of_parameters(rt_object, 4, 6));
	else
		return (ERROR);
}

int	check_rt_object_format(t_vla *rt_objects)
{
	size_t	idx;
	t_vla	*rt_object;

	idx = 0;
	while (idx < rt_objects->size)
	{
		rt_object = rt_objects->array[idx++];
		if (_check_rt_object(rt_object) == ERROR)
			return (ERROR);
	}
	return (SUCCESS);
}
