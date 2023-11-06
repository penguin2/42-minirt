/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rt_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 19:32:27 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/06 13:45:11 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include "generator.h"
#include "define.h"
#include <stddef.h>

static int	_check_number_of_parameters(t_vla *rt_object,
										size_t required_parameters_max_size,
										size_t optional_parameters_max_size)
{
	const char	**required_parameters = rt_object->array[0];
	const char	**optional_parameters;
	size_t		idx;
	size_t		optional_parameters_counter;

	if (required_parameters_max_size < ft_strings_len(required_parameters))
		return (ERROR);
	optional_parameters_counter = 0;
	idx = 1;
	while (idx < rt_object->size)
	{
		optional_parameters = rt_object->array[idx++];
		optional_parameters_counter += ft_strings_len(optional_parameters) - 1;
		if (optional_parameters_max_size < optional_parameters_counter)
			return (ERROR);
	}
	return (SUCCESS);
}

static int	_check_rt_object(t_vla *rt_object)
{
	const char	**strings = rt_object->array[0];
	const char	*identifer = strings[0];

	if (ft_is_equal_str(identifer, "A"))
		return (_check_number_of_parameters(rt_object, 3, 0));
	else if (ft_is_equal_str(identifer, "C"))
		return (_check_number_of_parameters(rt_object, 4, 0));
	else if (ft_is_equal_str(identifer, "L"))
		return (_check_number_of_parameters(rt_object, 4, 0));
	else if (ft_is_equal_str(identifer, "cy"))
		return (_check_number_of_parameters(rt_object, 4, 6));
	else if (ft_is_equal_str(identifer, "pl"))
		return (_check_number_of_parameters(rt_object, 4, 6));
	else if (ft_is_equal_str(identifer, "sp"))
		return (_check_number_of_parameters(rt_object, 6, 6));
	else
		return (ERROR);
}

int	check_rt_format(t_vla *rt_objects)
{
	size_t	idx;
	t_vla	*rt_object;

	idx = 0;
	while (idx < rt_objects->size)
	{
		rt_object = rt_objects->array[idx];
		if (_check_rt_object(rt_object) == ERROR)
			return (ERROR);
	}
	return (SUCCESS);
}
