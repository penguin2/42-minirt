/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rt_object_format.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 19:32:27 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/23 22:22:52 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "identifer_and_parameter.h"
#include "define.h"
#include "utils.h"
#include "message_parse.h"
#include <stdbool.h>
#include <stddef.h>

static int	_check_bonus_rt_object(const t_vla *rt_object,
									const char *identifer)
{
	if (MODE == MODE_MANDATORY
		&& (ft_is_equal_str(identifer, ID_TRIANGLE)
			|| ft_is_equal_str(identifer, ID_QUADRIC)))
	{
		print_error(RT_TR_OR_QD);
		return (ERROR);
	}
	else if (ft_is_equal_str(identifer, ID_TRIANGLE))
		return (check_size_of_parameters(
				rt_object, TRIANGLE_MAX_SIZE, OBJECTS_OPTION_MAX_SIZE));
	else if (ft_is_equal_str(identifer, ID_QUADRIC))
		return (check_size_of_parameters(
				rt_object, QUADRIC_MAX_SIZE, OBJECTS_OPTION_MAX_SIZE));
	else
	{
		print_error(RT_IDENTIFER);
		return (ERROR);
	}
}

static int	_check_rt_object(const t_vla *rt_object)
{
	const char	**strings = rt_object->array[0];
	const char	*identifer = strings[0];

	if (ft_is_equal_str(identifer, ID_AMBIENT))
		return (check_size_of_parameters(
				rt_object, AMBIENT_MAX_SIZE, LIGHTS_OPTION_MAX_SIZE));
	else if (ft_is_equal_str(identifer, ID_CAMERA))
		return (check_size_of_parameters(
				rt_object, CAMERA_MAX_SIZE, LIGHTS_OPTION_MAX_SIZE));
	else if (ft_is_equal_str(identifer, ID_SPOT))
		return (check_size_of_parameters(
				rt_object, SPOT_MAX_SIZE, LIGHTS_OPTION_MAX_SIZE));
	else if (ft_is_equal_str(identifer, ID_CYLINDER))
		return (check_size_of_parameters(
				rt_object, CYLINDER_MAX_SIZE, OBJECTS_OPTION_MAX_SIZE));
	else if (ft_is_equal_str(identifer, ID_PLANE))
		return (check_size_of_parameters(
				rt_object, PLANE_MAX_SIZE, OBJECTS_OPTION_MAX_SIZE));
	else if (ft_is_equal_str(identifer, ID_SPHERE))
		return (check_size_of_parameters(
				rt_object, SPHERE_MAX_SIZE, OBJECTS_OPTION_MAX_SIZE));
	else
		return (_check_bonus_rt_object(rt_object, identifer));
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
