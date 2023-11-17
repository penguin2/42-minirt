/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rt_object_format.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 19:32:27 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/17 15:02:17 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include "generator.h"
#include "identifer_and_parameter.h"
#include "define.h"
#include <stdbool.h>
#include <stddef.h>

/**
* @brief Check if the format of the rt file is followed.
*		 Ensure that required parameters are not identifer only,
*		 that they are less than the maximum value of required parameters,
*		 that they are less than the maximum value of optional parameters,
*		 and that optional parameters begin with an optional start string
*		 and consist only of an optional string and optional parameters,
*		 and that optional parameters are appropriate.
*
* @param rt_objects vla with string as content vla with string as content.
* @param required_parameters_max_size required parameters max size
* @param optional_parameters_max_size optional parameters max size
*
* @return SUCCESS if the rt file format is followed, otherwise ERROR.
*/
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
	}
	return (check_rt_object_option_format(rt_object));
}

static int	_check_rt_object(const t_vla *rt_object)
{
	const char	**strings = rt_object->array[0];
	const char	*identifer = strings[0];

	if (ft_is_equal_str(identifer, ID_AMBIENT))
		return (_check_size_of_parameters(rt_object, 3, 0));
	else if (ft_is_equal_str(identifer, ID_CAMERA))
		return (_check_size_of_parameters(rt_object, 4, 0));
	else if (ft_is_equal_str(identifer, ID_SPOT))
		return (_check_size_of_parameters(rt_object, 4, 0));
	else if (ft_is_equal_str(identifer, ID_CYLINDER))
		return (_check_size_of_parameters(rt_object, 6, 7));
	else if (ft_is_equal_str(identifer, ID_PLANE))
		return (_check_size_of_parameters(rt_object, 4, 7));
	else if (ft_is_equal_str(identifer, ID_SPHERE))
		return (_check_size_of_parameters(rt_object, 4, 7));
	else if (MODE != MODE_MANDATORY && ft_is_equal_str(identifer, ID_TRIANGLE))
		return (_check_size_of_parameters(rt_object, 5, 7));
	else if (MODE != MODE_MANDATORY && ft_is_equal_str(identifer, ID_QUADRIC))
		return (_check_size_of_parameters(rt_object, 8, 7));
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
